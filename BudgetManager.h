#include <iostream>
#include <windows.h>
#include <iterator>
#include "UserManager.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"
//ostatnio usunalem "Expenses.h" i "Incomes.h" w razie problemow przywrocic

using namespace std;

class BudgetManager
{
    UserManager userManager;
    vector <Income> incomes;
    vector <Expense> expenses;
    IncomesFile incomesFile;
    ExpensesFile expensesFile;

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
