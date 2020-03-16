/**
 * test.cpp
 *
 * <Eoin Sansevero>
 * <eoins>
 *
 * EECS 183: Project 2
 *
 * Testing functions for your birthdays.cpp implementation.
 * Holds the definitions of required testing functions.
 * We have stubbed all required functions for you.
 */

#include <cassert>
#include <cctype>
#include <iostream>
#include <limits>
#include <string>

using namespace std;


//************************************************************************
// You should have implemented the following functions in birthdays.cpp
//************************************************************************

bool isLeapYear (int year);
bool isGregorianDate(int m, int d, int y);
bool isValidDate(int month, int day, int year);
int determineDay (int month, int day, int year);


//************************************************************************
// Put all your test function implementations below here.
// We have stubbed all required functions for you 
// to recieve full points when submitting test.cpp
//************************************************************************

int getMenuChoice();
void printDayOfBirth(int day);
void determineDayOfBirth();
void print10Birthdays();
void print10LeapYears();


static void test_isLeapYear() {

    cout << isLeapYear(2016) << " correct value is: 1" << endl;
    cout << isLeapYear(2020) << " correct value is: 1" << endl;
    cout << isLeapYear(2018) << " correct value is: 0" << endl;
    cout << isLeapYear(1927) << " correct value is: 0" << endl;
    cout << isLeapYear(1756) << " correct value is: 1" << endl;
    cout << isLeapYear(2100) << " correct value is: 0" << endl;
    cout << isLeapYear(1856) << " correct value is: 1" << endl;
    cout << isLeapYear(4302) << " correct value is: 0" << endl;
    cout << isLeapYear(1999) << " correct value is: 0" << endl;
    cout << isLeapYear(1753) << " correct value is: 0" << endl;
    cout << isLeapYear(2001) << " correct value is: 0" << endl;
    cout << isLeapYear(1977) << " correct value is: 0" << endl;
    cout << isLeapYear(2008) << " correct value is: 1" << endl;
    cout << isLeapYear(2015) << " correct value is: 0" << endl;
    cout << isLeapYear(2012) << " correct value is: 1" << endl;
    cout << isLeapYear(1828) << " correct value is: 1" << endl;
    cout << isLeapYear(1976) << " correct value is: 1" << endl;
    cout << isLeapYear(2400) << " correct value is: 1" << endl;
    cout << isLeapYear(2401) << " correct value is: 0" << endl;

}

void test_isGregorianDate() {

    cout << isGregorianDate(11, 13, 1752) << " correct value: 1" << endl;
    cout << isGregorianDate(10, 13, 1752) << " correct value: 1" << endl;
    cout << isGregorianDate(9, 13, 1752) << " correct value: 0" << endl;
    cout << isGregorianDate(9, 12, 1752) << " correct value: 0" << endl;
    cout << isGregorianDate(9, 14, 1752) << " correct value: 1" << endl;
    cout << isGregorianDate(10, 14, 1752) << " correct value: 1" << endl;
    cout << isGregorianDate(11, 14, 1752) << " correct value: 1" << endl;
    cout << isGregorianDate(9, 13, 1753) << " correct value: 1" << endl;
    cout << isGregorianDate(9, 14, 1753) << " correct value: 1" << endl;
    cout << isGregorianDate(9, 13, 1751) << " correct value: 0" << endl;
    cout << isGregorianDate(9, 14, 1751) << " correct value: 0" << endl;
    cout << isGregorianDate(1, 1, 0001) << " correct value: 0" << endl;
    cout << isGregorianDate(0, 0, 0) << " correct value: 0" << endl;
    cout << isGregorianDate(1, 2, -1752) << " correct value: 0" << endl;
    cout << isGregorianDate(9, 26, 2018) << " correct value: 1" << endl;
    cout << isGregorianDate(5, 4, 2002) << " correct value: 1" << endl;
    cout << isGregorianDate(-1, 56, 1752) << " correct value: 0" << endl;
    cout << isGregorianDate(1, 56, -1885) << " correct value: 0" << endl;
    cout << isGregorianDate(1, -29, 1999) << " correct value: 0" << endl;
    cout << isGregorianDate(13, 2, 1987) << " correct value: 0" << endl;
    cout << isGregorianDate(90, 2, 2000) << " correct value: 0" << endl;
    cout << isGregorianDate(5, 2, 200) << " correct value: 0" << endl;
    cout << isGregorianDate(2003, 23, 1952) << " correct value: 0" << endl;
    cout << isGregorianDate(6, 1999, 23) << " correct value: 0" << endl;
    cout << isGregorianDate(6, 5, 4) << " correct value: 0" << endl;
    cout << isGregorianDate(1, 1, 1752) << " correct value: 0" << endl;

}
   
static void test_isValidDate() {

    cout << isValidDate(11, 13, 1752) << " correct value: 1" << endl;
    cout << isValidDate(10, 13, 1752) << " correct value: 1" << endl;
    cout << isValidDate(9, 13, 1752) << " correct value: 0" << endl;
    cout << isValidDate(9, 14, 1752) << " correct value: 1" << endl;
    cout << isValidDate(10, 14, 1752) << " correct value: 1" << endl;
    cout << isValidDate(11, 14, 1752) << " correct value: 1" << endl;
    cout << isValidDate(9, 13, 1753) << " correct value: 1" << endl;
    cout << isValidDate(9, 14, 1753) << " correct value: 1" << endl;
    cout << isValidDate(9, 13, 1751) << " correct value: 0" << endl;
    cout << isValidDate(9, 14, 1751) << " correct value: 0" << endl;
    cout << isValidDate(1, 1, 0001) << " correct value: 0" << endl;
    cout << isValidDate(0, 0, 0) << " correct value: 0" << endl;
    cout << isValidDate(1, 2, -1752) << " correct value: 0" << endl;
    cout << isValidDate(9, 26, 2018) << " correct value: 1" << endl;
    cout << isValidDate(5, 4, 2002) << " correct value: 1" << endl;
    cout << isValidDate(17, 4, 2000) << " correct value: 0" << endl;
    cout << isValidDate(10, 34, 2000) << " correct value: 0" << endl;
    cout << isValidDate(1, 4, 4656) << " correct value: 1" << endl;
    cout << isValidDate(9, 31, 1999) << " correct value: 0" << endl;
    cout << isValidDate(10, 31, 5783) << " correct value: 1" << endl;
    cout << isValidDate(2, 29, 2000) << " correct value: 1" << endl;
    cout << isValidDate(2, 29, 2001) << " correct value: 0" << endl;
    cout << isValidDate(1, 0, 2015) << " correct value: 0" << endl;


}

static void test_determineDay() {

    cout << determineDay(5, 15, 1979) << " correct value: 3" << endl;
    cout << determineDay(5, 16, 1979) << " correct value: 4" << endl;
    cout << determineDay(5, 17, 1979) << " correct value: 5" << endl;
    cout << determineDay(5, 18, 1979) << " correct value: 6" << endl;
    cout << determineDay(5, 19, 1979) << " correct value: 0" << endl;
    cout << determineDay(5, 20, 1979) << " correct value: 1" << endl;
    cout << determineDay(5, 21, 1979) << " correct value: 2" << endl;
    cout << determineDay(1, 3, 1979) << " correct value: 4" << endl;
    cout << determineDay(2, 3, 1979) << " correct value: 0" << endl;

}


void test_getMenuChoice() {
    cout << "testing good input" << endl;
    cout << getMenuChoice() << " should be choice 1" << endl;     // input 1 - 1
    cout << getMenuChoice() << " should be choice 2" << endl;     // input 2 - 2
    cout << getMenuChoice() << " should be choice 3" << endl;     // input 3 - 3
    cout << getMenuChoice() << " should be choice 4" << endl;     // input 4 - 4
    cout << endl;
    cout << "testing bad input" << endl;
    cout << "Test a bad input value and then pass 4 to getMenuChoice() to move onto the next test" << endl;
    cout << endl;
    cout << getMenuChoice() << " should print Invalid Choice and then print menu until valid input...in this case 4" << endl;     //5 (not a choice on the menu)
    cout << getMenuChoice() << " should print Invalid Choice and then print menu until valid input...in this case 4" << endl;     //-1 (not a choice on the menu)
}

//MAIN FUNCTION
/*
int main(int argc, char *argv[]) {
    
    test_isLeapYear();
    cout << endl;
    test_isGregorianDate();
    cout << endl; 
    test_isValidDate();
    cout << endl;
    test_determineDay();
    cout << endl;
    test_getMenuChoice();    
}

*/