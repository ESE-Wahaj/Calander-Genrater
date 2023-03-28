#include <iostream>
using namespace std;

int main() {
    int month, year;

    // Input month and year
    cout << "\n     0.Enter 0 if you want Calender of a YEAR. \n     1.Enter 1 if you want Calender of a MONTH.\n     2.Enter 2 if want to check for LEAP YEAR\n";
    int req;
    cin >> req;
    switch (req) {
        case 0:
            cout << "Enter month (1-12): ";
            cin >> month;
            cout << "Enter year: ";
            cin >> year;
            if (month <= 12 && month >= 1 && year >= 1 && year <= 2100) {

                // Determine number of days in the given month and year
                int numDays;
                if (month == 2) {
                    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
                        numDays = 29;
                    } else {
                        numDays = 28;
                    }
                } else if (month == 4 || month == 6 || month == 9 || month == 11) {
                    numDays = 30;
                } else {
                    numDays = 31;
                }

                // Determine the day of the week for the 1st of the given month and year
                int dayOfWeek;
                int y = year - (14 - month) / 12;
                int m = month + 12 * ((14 - month) / 12) - 2;
                dayOfWeek = (1 + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;

                // Output calendar
                cout << "\n     " << month << "/" << year << "\n";
                cout << "Su Mo Tu We Th Fr Sa\n";
                for (int i = 0; i < dayOfWeek; i++) {
                    cout << "   ";
                }
                for (int i = 1; i <= numDays; i++) {
                    if (i < 10) {
                        cout << " ";
                    }
                    cout << i << " ";
                    if ((i + dayOfWeek) % 7 == 0) {
                        cout << "\n";
                    }
                }
                cout << "\n";

            } else
                cout << "Please Enter Valid Inputs";
            break;

        case 1:
            cout << "Enter year: ";
            cin >> year;
            for(month=1;month<=12;month++) {

                    // Determine number of days in the given month and year
                    int numDays;
                    if (month == 2) {
                        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
                            numDays = 29;
                        } else {
                            numDays = 28;
                        }
                    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
                        numDays = 30;
                    } else {
                        numDays = 31;
                    }

                    // Determine the day of the week for the first of the given month and year
                    int dayOfWeek;
                    int y = year - (14 - month) / 12;
                    int m = month + 12 * ((14 - month) / 12) - 2;
                    dayOfWeek = (1 + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;

                    // Output calendar
                    cout << "\n     " << month << "/" << year << "\n";
                    cout << "Su Mo Tu We Th Fr Sa\n";
                    for (int i = 0; i < dayOfWeek; i++)
                        cout << "   ";

                    for (int i = 1; i <= numDays; i++) {
                        if (i < 10)
                            cout << " ";
                        cout << i << " ";

                        if ((i + dayOfWeek) % 7 == 0)
                            cout << "\n";
                    }
                    cout << "\n";
            }
            break;
        case 2:
            cout << "Enter year: ";
            cin >> year;
            if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
                cout<<"             Yes this is a leap year";
            } else {
                cout<<"             No The year you Entered is not a leap year";
            }
            break;
        default:
            cout << "               Invalid Input";
    }
    return 0;
}