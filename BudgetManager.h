#include <iostream>
#include <windows.h>
#include <iterator>
#include "UserManager.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"

using namespace std;

class BudgetManager
{
    UserManager userManager;
    vector <Income> incomes;
    vector <Expense> expenses;
    IncomesFile incomesFile;
    ExpensesFile expensesFile;

    double checkCurrentMonthIncomes();
    double checkCurrentMonthExpenses();
    double checkPreviousMonthIncomes();
    double checkPreviousMonthExpenses();

public:
    BudgetManager(string usersFileName, string incomesFileName, string expensesFileName)
    : userManager(usersFileName), incomesFile(incomesFileName), expensesFile(expensesFileName){}

    int loginMenu();
    int mainMenu();
    int logout();
    int exit();
    void changePassword();
    void addIncome();
    void addExpense();
    void checkCurrentMonthBalance();
    void checkPreviousMonthBalance();
    void checkSpecificTimePeriodBalance();
};
