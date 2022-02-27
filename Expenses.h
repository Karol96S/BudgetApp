#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "HelperMethods.h"

using namespace std;

class Expense
{
   int expenseId;
   double amount;
   int date;
   string item;

   public:
    void setId(int newExpenseId);
    void setAmount(double newExpenseAmount);
    void setDate(int newExpenseDate);
    void setItem(string newExpenseItem);

    int getId();
    double getAmount();
    int getDate();
    string getItem();
    static vector <Expense> sortExpensesByDate(vector <Expense> expenses);
};
#endif
