#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Expenses.h"
#include "Markup.h"
#include "HelperMethods.h"

using namespace std;

class ExpensesFile
{
    CMarkup expenseXml;
    const string EXPENSES_FILE_NAME;

public:
    ExpensesFile(string expensesFileName) : EXPENSES_FILE_NAME(expensesFileName) {}

    void addExpenseToXml(Expense &expense, int loggedInUserId);
    vector <Expense> readExpenseFromFile(int loggedInUserId);
};
#endif
