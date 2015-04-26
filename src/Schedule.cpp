#include <iostream>
#include <iomanip>
#include <algorithm>
#include <conio.h>
#include <stdlib.h>
#include <limits>
#include "Schedule.h"

using namespace std;

const string NAMES_OF_INSTUCTORS[] = {"Jeff", "Anna", "Peter", "Michael", "Kerry"};
const string ABBREVIATIONS[] = {"J", "A", "P", "M", "K"};
const string EMPTY_STRING = "";

/// Constructor of the Schedule class
Schedule::Schedule() {

    initialiseInstructorsAndSchedules();
    initialiseOverallSchedule();
}

/// \brief
/// Helper method to initialise the arrays of instructor
/// and instructors' Schedules
void Schedule::initialiseInstructorsAndSchedules() {

    for (int i = 0; i < NUMBER_OF_INSTRUCTORS; i++) {
        for (int j = 0; j < TIME_SLOTS; j++) {
            for (int k = 0; k < WORKING_DAYS; k++) {
                _instructors[i][j][k] = false;
                _instructorSchedule[i][j][k] = EMPTY_STRING;
            }
        }
    }
}

/// \brief
/// Helper method to initialise the arrays of overall schedule
void Schedule::initialiseOverallSchedule() {

    for (int i = 0; i < TIME_SLOTS; i++) {
        for (int j = 0; j < WORKING_DAYS; j++) {
        _overallSchedule[i][j] = EMPTY_STRING;
        }
    }
}

/// \brief
/// Getter for an instructor's time slot
bool Schedule::getInstructorTimeSlot(int instructor, int day, int time) {

    return _instructors[instructor-1][time-1][day-1];
}

/// \brief
/// Booking a swimming lesson for a member
///
/// \param instructor int - selected instructor
/// \param day int - preferred day
/// \param time int - preferred time
void Schedule::bookSwimmingLesson(int instructor, int day, int time) {

    _instructors[instructor-1][time-1][day-1] = true;
    _instructorSchedule[instructor-1][time-1][day-1] = "x";
}

/// \brief
/// Cancel a swimming lesson for a member
///
/// \param instructor int - selected instructor
/// \param day int - preferred day
/// \param time int - preferred time
void Schedule::cancelSwimmingLesson(int instructor, int day, int time) {

    _instructors[instructor-1][time-1][day-1] = false;
    _instructorSchedule[instructor-1][time-1][day-1] = EMPTY_STRING;
}

/// \brief
/// Display an instructor's current schedule
///
/// \param instructor int - selected instructor
void Schedule::displayInstructorSchdule(int instructor) {

    string instructorName = NAMES_OF_INSTUCTORS[instructor-1];
    int timeSystem = 12;
    int time = 9;

    cout << endl;
    cout << setw(30) << instructorName << "'s Current Schedule" << endl << endl;
    cout << "\t____________________________________________________________" << endl << endl;
    cout << setw(14) << instructorName << setw(10) << "Monday" << setw(10) << "Tuesday"
         << setw(12) << "Wednesday" << setw(11) << "Thursday" << setw(9) << "Friday" << endl;
    cout << "\t____________________________________________________________" << endl << endl;

    for (int i = 0; i < TIME_SLOTS; i++) {
        if (time == timeSystem-1) {
            cout << setw(10) << (time % timeSystem) << "-" << ((time+1)) << setw(8);
        } else {
            if (time % timeSystem < timeSystem/2) {
                cout << setw(11) << (time % timeSystem) << "-" << ((time+1) % timeSystem) << setw(8);
            } else {
                cout << setw(10) << (time % timeSystem) << "-" << ((time+1) % timeSystem) << setw(8);
            }
        }
        for (int j = 0; j < WORKING_DAYS; j++) {
            if (j > 0) {
                cout << _instructorSchedule[instructor-1][i][j] << setw(11);
            } else {
                cout << _instructorSchedule[instructor-1][i][j] << setw(10);
            }
            if (j == WORKING_DAYS-1) {
                cout << endl;
            }
        }
        time++;
        if (time == 12) {
            time++;
        }
    }
    cout << "\t____________________________________________________________" << endl << endl;
}

/// \brief
/// Display the overall schedule
void Schedule::displayOverallSchedule() {

    int timeSystem = 12;
    int time = 9;

    cout << endl;
    cout << setw(52) << "All Available Time Slots" << endl << endl;
    cout << "   _________________________________________________________________________" << endl << endl;
    cout << setw(18) << "Monday" << setw(15) << "Tuesday" << setw(15) << "Wednesday" << setw(14)
         << "Thursday" << setw(12) << "Friday" << endl;
    cout << "   _________________________________________________________________________" << endl << endl;

    for (int i = 0; i < TIME_SLOTS; i++) {
        if (time == timeSystem-1) {
            cout << setw(5) << (time % timeSystem) << "-" << ((time+1)) << setw(timeSystem);
        } else {
            if (time % timeSystem < timeSystem/2) {
                cout << setw(6) << (time % timeSystem) << "-" << ((time+1) % timeSystem) << setw(12);
            } else {
                cout << setw(5) << (time % timeSystem) << "-" << ((time+1) % timeSystem) << setw(12);
            }
        }
        for (int j = 0; j < WORKING_DAYS; j++) {
            cout << _overallSchedule[i][j] << setw(14);
            if (j == WORKING_DAYS-1) {
                cout << endl;
            }
        }
        time++;
        if (time == timeSystem) {
            time++;
        }
    }
    cout << "   _________________________________________________________________________" << endl << endl;
}

/// \brief
/// Clear the current schedule
void Schedule::clearSchedule() {

    initialiseInstructorsAndSchedules();
    initialiseOverallSchedule();
}

/// \brief
/// Display program name
void Schedule::displayProgramName() {

    cout << "\t\t__________________________________________" << endl << endl;
    cout << "\t\t\tSWIMMING LESSONS BOOKING" << endl;
    cout << "\t\t__________________________________________" << endl << endl;
}

/// \brief
/// Display main menu
void Schedule::displayMainMenus() {

    displayProgramName();

    cout << endl;
    cout << "\t\t\t\tMAIN MENUS" << endl << endl;
    cout << "\t\t1) Book a swimming lesson" << endl;
    cout << "\t\t2) Cancel a swimming lesson" << endl;
    cout << "\t\t3) Display the current schedule of a swimming instructor" << endl;
    cout << "\t\t4) Display all time slots available for booking" << endl;
    cout << "\t\t5) Clear all the schedule" << endl << endl;
    cout << "\t\tPress 0 to exit the program" << endl << endl;
}

/// \brief
/// Display instructors
void Schedule::displayInstructors() {

    cout << endl;
    cout << "\tLIST OF SWIMMING INSTRUCTORS" << endl << endl;
    cout << "\t1) Jeff" << endl;
    cout << "\t2) Anna" << endl;
    cout << "\t3) Peter" << endl;
    cout << "\t4) Michael" << endl;
    cout << "\t5) Kerry" << endl << endl;
    cout << "\tPress 0 to go back the main menu." << endl << endl;
}

/// \brief
/// Display day options
void Schedule::displayDaysOptions() {

    cout << endl;
    cout << "\tDAYS OPTIONS" << endl << endl;
    cout << "\t1) Monday" << endl;
    cout << "\t2) Tuesday" << endl;
    cout << "\t3) Wednesday" << endl;
    cout << "\t4) Thursday" << endl;
    cout << "\t5) Friday" << endl << endl;
    cout << "\tPress 0 to go back the main menu." << endl << endl;

}

/// \brief
/// Display time options
void Schedule::displayTimeOptions() {

    cout << endl;
    cout << "\tTIME OPTIONS" << endl << endl;
    cout << "\t1) 9am  - 10am" << endl;
    cout << "\t2) 10am - 11am" << endl;
    cout << "\t3) 11am - 12am" << endl;
    cout << "\t4) 1pm  - 2pm" << endl;
    cout << "\t5) 2pm  - 3pm" << endl;
    cout << "\t6) 3pm  - 4pm" << endl;
    cout << "\t7) 4pm  - 5pm" << endl << endl;
    cout << "\tPress 0 to go back the main menu." << endl << endl;

}

/// \brief
/// Modeling the overall schedule
void Schedule::fillOverallSchedule() {

    int **timeCount = getTimeCount();
    initialiseTimeCount(timeCount);

    initialiseOverallSchedule();

    string abbr = EMPTY_STRING;
    string slash = EMPTY_STRING;

    for (int i = 0; i < NUMBER_OF_INSTRUCTORS; i++) {
        abbr = ABBREVIATIONS[i];
        for (int j = 0; j < TIME_SLOTS; j++) {
            for (int k = 0; k < WORKING_DAYS; k++) {
				if (_instructors[i][j][k] == true) {
				    timeCount[j][k]++;
                    if (timeCount[j][k] == NUMBER_OF_INSTRUCTORS) {
                    _overallSchedule[j][k] += "    x    ";
                    }
					_overallSchedule[j][k] += EMPTY_STRING;
				} else if (_instructors[i][j][k] == false) {
					if (_overallSchedule[j][k] == EMPTY_STRING) {
					slash = EMPTY_STRING;
					} else {
					slash = "/";
					}
					_overallSchedule[j][k] += slash + abbr;
				}
            }
        }
    }

    delete[] timeCount;
}

/// \brief
/// Get selected menu from user
///
/// \return int - a menu selected by user
int Schedule::getMenu() {

    int menu;

    do {
        cout << "\t\tSelect a menu (options 1-5): ";
        cin >> menu;

        while (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            displayErrorMessage();
            cout << "\t\tSelect a menu (options 1-5): ";
            cin >> menu;
        }

        if (menu < 0 || menu > 5) {
            displayErrorMessage();
        }
    } while (menu < 0 || menu > 5);

    system("CLS");

    return menu;
}

/// \brief
/// Get selected instructor from user
///
/// \return int - an instructor selected by user
int Schedule::getInstructor() {

    int instructor;

    do {
        displayInstructors();
        cout << "\tSelect an instructor (options 1-5): ";
        cin >> instructor;

        while (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            displayErrorMessage();
            cout << "\tSelect an instructor (options 1-5): ";
            cin >> instructor;
        }

        if (instructor < 0 || instructor > 5) {
            displayErrorMessage();
        }
    } while (instructor < 0 || instructor > 5);

    return instructor;
}

/// \brief
/// Get preferred day from user
///
/// \return int - a day selected by user
int Schedule::getDay() {

    int day;

    do {
        displayDaysOptions();
        cout << "\tEnter a day (options 1-5): ";
        cin >> day;

        while (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            displayErrorMessage();
            cout << "\tEnter a day (options 1-5): ";
            cin >> day;
        }

        if (day < 0 || day > 5) {
            displayErrorMessage();
        }
    } while (day < 0 || day > 5);

    return day;
}

/// \brief
/// Get preferred time from user
///
/// \return int - a time selected by user
int Schedule::getTime() {

    int time;

    do {
        displayTimeOptions();
        cout << "\tEnter a lesson duration (options 1-7): ";
        cin >> time;

        while (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            displayErrorMessage();
            cout << "\tEnter a lesson duration (options 1-7): ";
            cin >> time;
        }

        if (time < 0 || time > 7) {
            displayErrorMessage();
        }
    } while (time < 0 || time > 7);

    return time;
}

/// \brief
/// Generate the timeCount parameter
/// Using for counting unavailable instructors in each time slot
///
/// \return int** - a pointer to a 2D array used for counting
///         unavailable instructors in each time slot
int** Schedule::getTimeCount() {

    int **timeCount = new int*[TIME_SLOTS];

    for (int i = 0; i < TIME_SLOTS; i++) {
        timeCount[i] = new int[WORKING_DAYS];
    }

    return timeCount;
}

/// \brief
/// Initialise the timeCount parameter
/// Using for counting unavailable instructors in each time slot
void Schedule::initialiseTimeCount(int **timeCount) {

    for (int i = 0; i < TIME_SLOTS; i++) {
        for (int j = 0; j < WORKING_DAYS; j++) {
            timeCount[i][j] = 0;
        }
    }
}

/// \brief
/// Display details for confirmation
///
/// \param instructor int - selected instructor
/// \param day int - preferred day
/// \param time int - preferred time
void Schedule::displayDetails(int instructor, int day, int time) {

    cout << endl << "\tDETAILS CONFIRMATION" << endl << endl;
    cout << "\tInstructor: ";
    switch (instructor) {
    case (1):
        cout << "Jeff" << endl;
        break;
    case (2):
        cout << "Anna" << endl;
        break;
    case (3):
        cout << "Peter" << endl;
        break;
    case (4):
        cout << "Michael" << endl;
        break;
    case (5):
        cout << "Kerry" << endl;
        break;
    }

    cout << "\tDay: ";
    switch (day) {
    case (1):
        cout << "Monday" << endl;
        break;
    case (2):
        cout << "Tuesday" << endl;
        break;
    case (3):
        cout << "Wednesday" << endl;
        break;
    case (4):
        cout << "Thursday" << endl;
        break;
    case (5):
        cout << "Friday" << endl;
        break;
    }

    cout << "\tTime: ";
    switch (time) {
    case (1):
        cout << "9am - 10am" << endl;
        break;
    case (2):
        cout << "10am - 11am" << endl;
        break;
    case (3):
        cout << "11am - 12am" << endl;
        break;
    case (4):
        cout << "1pm - 2pm" << endl;
        break;
    case (5):
        cout << "2pm - 3pm" << endl;
        break;
    case (6):
        cout << "3pm - 4pm" << endl;
        break;
    case (7):
        cout << "4pm - 5pm" << endl;
        break;
    }
}

/// \brief
/// Receive confirmation from user
///
/// \param instructor int - selected instructor
/// \param day int - preferred day
/// \param time int - preferred time
/// \return int - user confirmation
int Schedule::confirmDetails(int instructor, int day, int time) {

    int confirm;

    system("CLS");
    displayDetails(instructor, day, time);

    do {
        cout << endl << "\t1) Confirm" << endl;
        cout << "\t2) Cancel (back to the main menu)" << endl;
        cout << endl << "\tEnter an option: ";
        cin >> confirm;

        while (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            displayErrorMessage();
            cout << endl << "\t1) Confirm" << endl;
            cout << "\t2) Cancel (back to the main menu)" << endl;
            cout << endl << "\tEnter an option: ";
            cin >> confirm;
        }

        if (confirm < 1 || confirm > 2) {
            displayErrorMessage();
        }
    } while (confirm < 1 || confirm > 2);

    return confirm;
}

/// \brief
/// Receive confirmation for clearing the schedule
///
/// \return int - user confirmation
int Schedule::confirmClearSchedule() {

    int confirm;

    system("CLS");

    do {
        cout << endl << "\tWould you like to clear all the schedule?" << endl;
        cout << endl << "\t1) Confirm" << endl;
        cout << "\t2) Cancel (back to the main menu)" << endl;
        cout << endl << "\tEnter an option: ";
        cin >> confirm;

        while (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            displayErrorMessage();
            cout << endl << "\tWould you like to clear all the schedule?" << endl;
            cout << endl << "\t1) Confirm" << endl;
            cout << "\t2) Cancel (back to the main menu)" << endl;
            cout << endl << "\tEnter an option: ";
            cin >> confirm;
        }

        if (confirm < 1 || confirm > 2) {
            displayErrorMessage();
        }
    } while (confirm < 1 || confirm > 2);

    return confirm;
}

/// \brief
/// Display a message if a particular time slot is already booked
void Schedule::displayBookedTimeSlotMessage() {

    cout << endl << "\tThe selected time is unavailable." << endl;
    cout << "\tPlease change the day or time for your reservation." << endl << endl;
    cout << "\tPress any key to go back to the main menu..." << endl << endl;
    getch();
    system("CLS");
}

/// \brief
/// Display a message if a particular time slot is still available
void Schedule::diaplayFreeTimeSlotMessage() {

    cout << endl << "\tThe selected time is still available." << endl;
    cout << "\tPlease change the time for your cancellation." << endl << endl;
    cout << "\tPress any key to go back to the main menu..." << endl << endl;
    getch();
    system("CLS");
}

/// \brief
/// Clear the terminal
void Schedule::backToMainMenu() {

    system("CLS");
}

/// \brief
/// Display a continuity message and wait until user presses any key
void Schedule::displayContinueMessage() {

    cout << endl << "\tPress any key to continue..." << endl << endl;
    getch();
    system("CLS");
}

/// \brief
/// Display an error message for invalid input
void Schedule::displayErrorMessage() {

    cout << endl << "\tERROR: Invalid Input." << endl << endl;
}
