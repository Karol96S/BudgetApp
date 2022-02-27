#include "Incomes.h"

void Income::setId(int newIncomeId)
{
    if(newIncomeId >= 0)
    {
        incomeId = newIncomeId;
    }
}

void Income::setAmount(double newIncomeAmount)
{
    amount = newIncomeAmount;
}

void Income::setDate(int newIncomeDate)
{
    date = newIncomeDate;
}

void Income::setItem(string newIncomeItem)
{
    item = newIncomeItem;
}

int Income::getId()
{
    return incomeId;
}

double Income::getAmount()
{
    return amount;
}

int Income::getDate()
{
    return date;
}

string Income::getItem()
{
    return item;
}

vector <Income> Income::sortIncomesByDate(vector <Income> incomes)
{
    sort(incomes.begin(),
         incomes.end(),
         [](const Income &lhs, const Income &rhs)
    {
        return lhs.date < rhs.date;
    });
    return incomes;
}
