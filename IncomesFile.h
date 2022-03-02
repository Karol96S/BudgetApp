#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "Incomes.h"
#include "HelperMethods.h"

using namespace std;

class IncomesFile
{
    CMarkup incomeXml;
    const string INCOMES_FILE_NAME;

public:
    IncomesFile(string incomesFileName) : INCOMES_FILE_NAME(incomesFileName) {}

    void addIncomeToXml(Income &income, int loggedInUserId);
    vector <Income> readIncomeFromFile(int loggedInUserId);
};
#endif
