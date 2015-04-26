#include <string>

#ifndef SCHEDULE_H
#define SCHEDULE_H

#define WORKING_DAYS 5
#define TIME_SLOTS 7
#define NUMBER_OF_INSTRUCTORS 5


/// This class provides several functions for modeling swimming lesson schedules

class Schedule {

    public:
        Schedule();
        bool getInstructorTimeSlot(int instructor, int day, int time);
        void bookSwimmingLesson(int instructor, int day, int time);
        void cancelSwimmingLesson(int instructor, int day, int time);
        void displayInstructorSchdule(int instructor);
        void displayOverallSchedule();
        void clearSchedule();
        void displayMainMenus();
        void fillOverallSchedule();
        int getMenu();
        int getInstructor();
        int getDay();
        int getTime();
        int confirmDetails(int instructor, int day, int time);
        int confirmClearSchedule();
        void displayBookedTimeSlotMessage();
        void diaplayFreeTimeSlotMessage();
        void backToMainMenu();
        void displayContinueMessage();

    private:
        bool _instructors[NUMBER_OF_INSTRUCTORS][TIME_SLOTS][WORKING_DAYS];
        std::string _instructorSchedule[NUMBER_OF_INSTRUCTORS][TIME_SLOTS][WORKING_DAYS];
        std::string _overallSchedule[TIME_SLOTS][WORKING_DAYS];

        /// Helper methods
        void initialiseInstructorsAndSchedules();
        void initialiseOverallSchedule();
        int **getTimeCount();
        void initialiseTimeCount(int **timeCount);
        void displayProgramName();
        void displayInstructors();
        void displayDaysOptions();
        void displayTimeOptions();
        void displayDetails(int instructor, int day, int time);
        void displayErrorMessage();
};

#endif // SCHEDULE_H
