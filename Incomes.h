#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "HelperMethods.h"

using namespace std;

class Income
{
   int incomeId;
   double amount;
   int date;
   string item;

   public:
    void setId(int newIncomeId);
    void setAmount(double newIncomeAmount);
    void setDate(int newIncomeDate);
    void setItem(string newIncomeItem);

    int getId();
    int getDate();
    double getAmount();
    string getItem();
    static vector <Income> sortIncomesByDate(vector <Income> incomes);
};
#endif
