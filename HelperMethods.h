#ifndef HELPERMETHODS_H
#define HELPERMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Incomes.h"
#include "Expenses.h"

using namespace std;

class HelperMethods
{

public:
    static string getLine();
    static int getNumber();
    static string convertIntToString(int numericValue);
    static int convertStringToInt(string text );
    static double convertStringToDouble(string userInputAmount);
    static string convertDoubleToString(double amount);
    static int getTodaysDate();
    static int getNumberOfDaysInAMonth(int month, int year);
    static bool checkIfDateIsCorrect(int date);
    static bool checkIfItsCurrentMonth(int date);
    static bool checkIfItsPreviousMonth(int date);
    static bool checkIfItsSelectedTimePeriod(int startingDateInt, int endingDateInt, int dateToCheck);
    static string changeDashedDateToNonDashed(string dateString);
    static string changeNonDashedDateToDashed(string dateNonDashed);
    static string changeComaToDot(string userInputAmount);
    //to samo z expense
};
#endif
