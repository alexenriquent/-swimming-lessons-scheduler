#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "Schedule.h"

using namespace std;

void bookingSystemOperations(Schedule scheduleObj, int menu, int instructor,
                             int day, int time, int confirm);

int main() {

    Schedule schedule;
    int menuOption;
    int instructorOption;
    int preferredDay;
    int preferredTime;
    int confirmDetails;

    bookingSystemOperations(schedule, menuOption, instructorOption,
             preferredDay, preferredTime, confirmDetails);

    return 0;
}

/// \brief
/// The main menu for the swimming lessons booking system
///
/// \param scheduleObj Schedule - a Schedule object
/// \param menu int - selected menu
/// \param instructor int - selected instructor
/// \param day int - preferred day
/// \param time int - preferred time
/// \param confirm int - details confirmation
void bookingSystemOperations(Schedule scheduleObj, int menu, int instructor,
                             int day, int time, int confirm) {

    do {
        scheduleObj.displayMainMenus();
        menu = scheduleObj.getMenu();
        switch (menu) {
        case (1):
            instructor = scheduleObj.getInstructor();
            if (instructor == 0) {
                scheduleObj.backToMainMenu();
                break;
            }
            day = scheduleObj.getDay();
            if (day == 0) {
                scheduleObj.backToMainMenu();
                break;
            }
            time = scheduleObj.getTime();
            if (time == 0) {
                scheduleObj.backToMainMenu();
                break;
            }

            if (scheduleObj.getInstructorTimeSlot(instructor, day, time) == true) {
                scheduleObj.displayBookedTimeSlotMessage();
                break;
            }

            confirm = scheduleObj.confirmDetails(instructor, day, time);
            if (confirm == 2) {
                scheduleObj.backToMainMenu();
                break;
            }

            scheduleObj.bookSwimmingLesson(instructor, day, time);
            scheduleObj.displayContinueMessage();
            break;
        case (2):
            instructor = scheduleObj.getInstructor();
            if (instructor == 0) {
                scheduleObj.backToMainMenu();
                break;
            }
            day = scheduleObj.getDay();
            if (day == 0) {
                scheduleObj.backToMainMenu();
                break;
            }
            time = scheduleObj.getTime();
            if (time == 0) {
                scheduleObj.backToMainMenu();
                break;
            }

            if (scheduleObj.getInstructorTimeSlot(instructor, day, time) == false) {
                scheduleObj.diaplayFreeTimeSlotMessage();
                break;
            }

            confirm = scheduleObj.confirmDetails(instructor, day, time);
            if (confirm == 2) {
                scheduleObj.backToMainMenu();
                break;
            }

            scheduleObj.cancelSwimmingLesson(instructor, day, time);
            scheduleObj.displayContinueMessage();
            break;
        case (3):
            instructor = scheduleObj.getInstructor();
            system("CLS");
            scheduleObj.displayInstructorSchdule(instructor);
            scheduleObj.displayContinueMessage();
            break;
        case (4):
            scheduleObj.fillOverallSchedule();
            scheduleObj.displayOverallSchedule();
            scheduleObj.displayContinueMessage();
            break;
        case (5):
            confirm = scheduleObj.confirmClearSchedule();
            if (confirm == 2) {
                scheduleObj.backToMainMenu();
                break;
            }
            scheduleObj.clearSchedule();
            scheduleObj.displayContinueMessage();
            break;
        }
    } while (menu != 0);
}
