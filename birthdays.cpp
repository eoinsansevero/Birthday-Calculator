/**
 * birthdays.cpp
 *
 * Name: Eoin Sansevero
 * Uniqname: eoins
 *
 * EECS 183: Project 2
 *
 * <This Project gives the user a menu of 
    functions to perform. The program will
    read in the user's choice and calculate
    the day of the week the user was born,
    the next 10 leap years, or (in the S'mores
    version) determine the next 10 birthdays.>
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  prints out the initial heading for the program
 */
void printHeading();


/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  prints out the final greeting for the program
 */
void printCloser();


/**
 * Requires: nothing
 * Modifies: cout 
 * Effects:  prints the menu
 */
void printMenu();


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Requires: nothing
 * Modifies: cout, cin
 * Effects:  prints the menu
 *           reads the input from the user
 *           checks to make sure the input is within range for the menu
 *           If not prints "Invalid menu choice"
 *           continues to print the menu and read an input until 
 *           a valid one is entered
 *           returns the users choice of menu options
 */
int getMenuChoice();


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Requires: month, day, year may represent a date
 * Modifies: nothing
 * Effects:  returns 'true' if the date is in the limits
 *           of the Gregorian calendar otherwise returns 'false'
 */
bool isGregorianDate(int month, int day, int year);


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Requires: year is a Gregorian year
 * Modifies: nothing
 * Effects:  returns 'true' if the year is a leap year
 *           otherwise returns 'false'
 */
bool isLeapYear(int year);


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Requires: month, day, year may represent a date
 * Modifies: nothing
 * Effects:  returns 'true' if the date is valid
 *           otherwise returns 'false'
 *           see the spec for definition of "valid"
 */
bool isValidDate(int month, int day, int year);


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Requires: month, day, year is a valid date
 *           i.e., the date passed to this function has already passed
 *               isValidDate()
 * Modifies: nothing
 * Effects:  returns the value that Zeller's formula calculates
 */
int determineDay(int month, int day, int year);


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Requires: day (0 represents Saturday, 1 Sunday, 2 Monday, 3 Tuesday, etc)
 * Modifies: cout
 * Effects:  prints the day you were born on
 *           Sunday, Monday, ..., Saturday
 */
void printDayOfBirth(int day);


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Requires: nothing
 * Modifies: cout, cin
 * Effects:  asks for the Month/day/year of their birth
 *           If the date is valid, it will print the day
 *           of the week you were born on
 *           Otherwise, it will print "Invalid date" prompt
 */
void determineDayOfBirth();


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Base Project
 * Requires: nothing
 * Modifies: cout
 * Effects: prints "Under Construction"
 *
 * S'more version of this function
 * Requires: nothing
 * Modifies: cout, cin 
 * Effects:  reads the month and day of birthday
 *           loops through 10 years printing the day of the week
 *           the birthday falls on
 *           If the month/day is not valid, it prints nothing
 */
void print10Birthdays();


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Requires: nothing
 * Modifies: cin, cout
 * Effects:  asks for a Gregorian year and prints the
 *           10 leap years after (not including) the year entered.
 *           If the year is invalid, it prints nothing.
 */
void print10LeapYears();

//Main
int main() {

    printHeading();

    //Local variable userChoice declared with scope of main function.

    int userChoice;
    userChoice = getMenuChoice();

    //Loops through user selections until choice 4 is selected.

    while (userChoice != 4) {
        if (userChoice == 1) {

            determineDayOfBirth();
            
        }
        else if (userChoice == 2) {

            print10LeapYears();

        }
        else if (userChoice == 3) {

            print10Birthdays();
         
        }
        //userChoice is assigned the return value of function getMenuChoice() at the end of each loop.
        //This updates the user's choice whenever the previous selection finishes.
        userChoice = getMenuChoice();
    }

    printCloser();

    //All is good.

    return 0;
}

void printHeading() {
    cout << "*******************************" << endl
        << "      Birthday Calculator      " << endl
        << "*******************************" << endl << endl;
    return;
}


void printCloser() {
    cout << endl;
    cout << "****************************************************" << endl
        << "      Thanks for using the Birthday Calculator      " << endl
        << "****************************************************" << endl
        << endl;
    return;
}


void printMenu() {
    cout << endl;
    cout << "Menu Options" << endl
        << "------------" << endl;
    cout << "1) Determine day of birth" << endl;
    cout << "2) Print the next 10 leap years" << endl;
    cout << "3) Determine birthdays for the next 10 years" << endl;
    cout << "4) Finished" << endl << endl;

    cout << "Choice --> ";
    return;
}

int getMenuChoice() {

    //gets user choice and stores in a local variable.

    printMenu();
    int choice;
    cin >> choice;

    //loops until the input is a valid choice of 1-4.

    while (choice < 1 || choice > 4) {
        cout << "Invalid menu choice";
        printMenu();
        cin >> choice;
    }

    //returns value of local variable choice.

    return choice;
}

bool isGregorianDate(int month, int day, int year) {

    //Gregorian Dates are after 9 / 13 / 1752
    if (month < 1 || month > 12) {
        return false;
    }

    if (day < 1 || day > 31) {
        return false;
    }

    if (year > 1752) {
        return true;
    }
    else if (year == 1752) {
        if (month > 9) {
            return true;
        }
        else if (month == 9) {
            if (day > 13) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

bool isLeapYear(int year) {

    //Every year >1752 that is divisible by 4 is leap year.
    /*Exceptions:
       if year is divisible by 100, it is not a leap year unless
       it is also divisible by 400.
    */

    if (year >= 1752) {
        if ((year % 4) == 0) {
            if ((year % 100) == 0 && (year % 400) == 0) {
                return true;
            }
            else if ((year % 100) == 0 && (year % 400) != 0) {
                return false;
            }
            else {
                return true;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

bool isValidDate(int month, int day, int year) {

    /*Months go from 1 - 12
      September, April, June, November have 30 days
      The rest have 31 days except February
      February has 28 days, unless it's a leap year
      If it is a leap year, February has 29 days
    */
   
    if (isGregorianDate(month, day, year) == true) {

        if (month < 1 || month > 12) {
            return false;
        }

        if (day < 1) {
            return false;
        }

        if (month == 4 || month == 6 || month == 9 || month == 11) {
            if (day > 30) {
                return false;
            }
            else {
                return true;
            }
        }
        else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            if (day > 31) {
                return false;
            }
            else {
                return true;
            }
        }
        else if (month == 2) {
            if (day > 29) {
                return false;
            }
        }

        if ((isLeapYear(year) == false) && (month == 2 && day == 29)) {
            return false;
        }
        else if ((isLeapYear(year) == true) && (month == 2 && day == 29)) {
            return true;
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}


int determineDay(int month, int day, int year) {

    //January and February conversion to Zeller Calendar

    if (month == 1) {
        month = 13;
        year -= 1;
    }
    else if (month == 2) {
        month = 14;
        year -= 1;
    }

    int f;
    int C = (int)(year / 100);
    int Y = year % 100;

    //Zeller's Rule

    f = ((day + ((13 * (int)(month + 1)) / 5) + Y + (int)(Y / 4) + (int)(C / 4) + 5 * C) % 7);

    return f;
}


void printDayOfBirth(int day) {

    string dayResult;

    //Day for the appropriate f value

    if (day == 0) {
        dayResult = "Saturday";
    }
    else if (day == 1) {
        dayResult = "Sunday";
    }
    else if (day == 2) {
        dayResult = "Monday";
    }
    else if (day == 3) {
        dayResult = "Tuesday";
    }
    else if (day == 4) {
        dayResult = "Wednesday";
    }
    else if (day == 5) {
        dayResult = "Thursday";
    }
    else {
        dayResult = "Friday";
    }

    cout << dayResult;
    
    return;
}


void determineDayOfBirth() {
    

    int userMonth;
    int userDay;
    int userYear;
    char slash1;
    char slash2;

    cout << "Enter your date of birth" << endl;
    cout << "format: month / day / year  -->" << endl;

    cin >> userMonth 
        >> slash1 
        >> userDay 
        >> slash2 
        >> userYear;

    if (isValidDate(userMonth, userDay, userYear) == true) {

        /*local int variable dayOfBirth declared to store return value
          of determineDay function, which is called with user input as 
          arguments.
          This int variable is then passed to printDayOfBirth function,
          which appropriately prints day of the week depending on the 
          parameter.
        */

        int dayOfBirth = determineDay(userMonth, userDay, userYear);

        cout << "You were born on a: ";
        printDayOfBirth(dayOfBirth);
        cout << endl;
        cout << endl;
        cout << "Have a great birthday!!!" << endl;

    }
    else {
        cout << "Invalid date" << endl;
    }
    
    
    return;
}

void print10Birthdays() {

    cout << "Under Construction";

    return;
}

void print10LeapYears() {
    
    int startYear;

    cout << "Enter year -->" << endl;
    cin >> startYear;

    /*Since we know the number of times we need to loop,
      10, a for loop is easier to use for count based 
      looping. 
      The variable startYear is set to equal the first leap
      year after the year that the user entered. The print
      of startYear marks the first iteration of the loop.
    */

    if (startYear >= 1752) {
        int numYears;
        if (isLeapYear(startYear) == true) {
            for (numYears = 0; numYears < 10; numYears++) {
                startYear += 4;
                cout << "Leap year is " << startYear << endl;
            }
        }
        else {
            if (isLeapYear(startYear + 1) == true) {
                startYear += 1;
            }
            else if (isLeapYear(startYear + 2) == true) {
                startYear += 2;
            }
            else if (isLeapYear(startYear + 3) == true) {
                startYear += 3;
            }

            for (numYears = 0; numYears < 10; numYears++) {
                cout << "Leap year is " << startYear << endl;
                startYear += 4; //increments after cout because the original input was not a leap year.
            }
        }
    }

    //No else statement because it prints nothing if year is invalid.

    
    return;
}
