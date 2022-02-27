#include "Expenses.h"

void Expense::setId(int newExpenseId)
{
    if(newExpenseId >= 0)
    {
        expenseId = newExpenseId;
    }
}

void Expense::setAmount(double newExpenseAmount)
{
    amount = newExpenseAmount;
}

void Expense::setDate(int newExpenseDate)
{
    date = newExpenseDate;
}

void Expense::setItem(string newExpenseItem)
{
    item = newExpenseItem;
}

int Expense::getId()
{
    return expenseId;
}

double Expense::getAmount()
{
    return amount;
}

int Expense::getDate()
{
    return date;
}

string Expense::getItem()
{
    return item;
}

vector <Expense> Expense::sortExpensesByDate(vector <Expense> expenses)
{
    sort(expenses.begin(),
         expenses.end(),
         [](const Expense &lhs, const Expense &rhs)
    {
        return lhs.date < rhs.date;
    });
    return expenses;
}
