#include "BudgetManager.h"

int BudgetManager::loginMenu()
{
    cin.clear();
    cin.sync();
    int userChoice = 0;

    system("cls");
    cout << "----------------------------------------------------------------" << endl;
    cout << "Welcome to budget manager app. please choose your action: " << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "1. Login." << endl;
    cout << "2. Register." << endl;
    cout << "3. Exit." << endl;
    cout << "-----------------------------------" << endl;
    cout << "Your choice: ";
    userChoice = HelperMethods::getNumber();

    if(userChoice == 1)
    {
        bool checkIfLoginWasSuccesfull = false;
        checkIfLoginWasSuccesfull = userManager.loginUser();

        if(checkIfLoginWasSuccesfull == true)
        {
            incomes = incomesFile.readIncomeFromFile(userManager.getLoggedInUserId());
            expenses = expensesFile.readExpenseFromFile(userManager.getLoggedInUserId());
            return 1;
        }

        else return 0;
    }

    else if(userChoice == 2)
    {
        userManager.addUser();
        return 0;
    }

    else if (userChoice == 3)
    {
        return -1;
    }

    else
    {
        cout << endl;
        cout << "Invalid input!" << endl;
        system("pause");
    }
}

int BudgetManager::mainMenu()
{
    int userChoice = 0;

    system("cls");
    cout << "----------------------------------------" << endl;
    cout << "           MAIN MENU" << "    user: " << userManager.getLoggedInUserName() << endl;
    cout << "----------------------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Check current month's balance" << endl;
    cout << "4. Check previous month's balance" << endl;
    cout << "5. Check specified date's balance" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Logout" << endl;
    cout << "8. Exit" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Your choice: ";
    userChoice = HelperMethods::getNumber();

    switch(userChoice)
    {
    case 1:
        addIncome();
        break;
    case 2:
        addExpense();
        break;
    case 3:
        checkCurrentMonthBalance();
        break;
    case 4:
        checkPreviousMonthBalance();
        break;
    case 5:
        checkSpecificTimePeriodBalance();
        break;
    case 6:
        changePassword();
        break;
    case 7:
        logout();
        break;
    case 8:
        exit();
        break;
    }

}

void BudgetManager::addIncome()
{
    Income income;
    int date = 0;
    double amount = 0;
    string choice = "", item = "", userInputAmount = "", dateString = "";

    while (choice != "y" && choice != "yes" && choice != "n" && choice != "no")
    {
        system("cls");
        cout << "Do you wish to add income to today's date?" << endl;
        cout << endl << "yes / no (y/n): ";
        cin >> choice;

        if (choice == "y" || choice == "yes")
        {
            system("cls");
            date = HelperMethods::getTodaysDate();
            cout << "Specify source of income: ";
            item = HelperMethods::getLine();
            cout << "Enter value of acquired income: ";
            cin >> userInputAmount;

            userInputAmount = HelperMethods::changeComaToDot(userInputAmount);
            amount = HelperMethods::convertStringToDouble(userInputAmount);
            income.setAmount(amount);
            income.setItem(item);
            income.setDate(date);

            if(incomes.size() == 0)
            {
                income.setId(1);
            }
            else
            {
                income.setId(incomes.back().getId()+1);
            }
            incomesFile.addIncomeToXml(income, userManager.getLoggedInUserId());
            incomes.push_back(income);
        }

        else if (choice == "n" || choice == "no")
        {
            do
            {
                system("cls");
                cout << "Enter date of acquired income as shown in the example yyyy-mm-dd: ";
                cin >> dateString;
                dateString = HelperMethods::changeDashedDateToNonDashed(dateString);
                date = HelperMethods::convertStringToInt(dateString);

                if(HelperMethods::checkIfDateIsCorrect(date) == false)
                {
                    cout << endl << "Given date is incorrect! Date should span between 2000-01-01 and last day of current month of this year." << endl;
                    system("pause");
                }
            }
            while( HelperMethods::checkIfDateIsCorrect(date)!= true );

            cout << "Specify source of income: ";
            item = HelperMethods::getLine();
            cout << "Enter value of acquired income: ";
            cin >> userInputAmount;

            userInputAmount = HelperMethods::changeComaToDot(userInputAmount);
            amount = HelperMethods::convertStringToDouble(userInputAmount);
            income.setAmount(amount);
            income.setItem(item);
            income.setDate(date);

            if(incomes.size() == 0)
            {
                income.setId(1);
            }
            else
            {
                income.setId(incomes.back().getId()+1);
            }
            incomesFile.addIncomeToXml(income, userManager.getLoggedInUserId());
            incomes.push_back(income);
        }
    }
}

void BudgetManager::addExpense()
{
    Expense expense;
    int date = 0;
    double amount = 0;
    string choice = "", item = "", userInputAmount = "", dateString = "";

    while (choice != "y" && choice != "yes" && choice != "n" && choice != "no")
    {
        system("cls");
        cout << "Do you wish to add expense to today's date?" << endl;
        cout << endl << "yes / no (y/n): ";
        cin >> choice;

        if (choice == "y" || choice == "yes")
        {
            system("cls");
            date = HelperMethods::getTodaysDate();
            cout << "Specify type of expense: ";
            item = HelperMethods::getLine();
            cout << "Enter value of that expense: ";
            cin >> userInputAmount;

            userInputAmount = HelperMethods::changeComaToDot(userInputAmount);
            amount = HelperMethods::convertStringToDouble(userInputAmount);
            expense.setAmount(amount);
            expense.setItem(item);
            expense.setDate(date);

            if(expenses.size() == 0)
            {
                expense.setId(1);
            }
            else
            {
                expense.setId(expenses.back().getId()+1);
            }
            expensesFile.addExpenseToXml(expense, userManager.getLoggedInUserId());
            expenses.push_back(expense);
        }

        else if (choice == "n" || choice == "no")
        {
            do
            {
                system("cls");
                cout << "Enter date of expense as shown in the example yyyy-mm-dd: ";
                cin >> dateString;
                dateString = HelperMethods::changeDashedDateToNonDashed(dateString);
                date = HelperMethods::convertStringToInt(dateString);

                if(HelperMethods::checkIfDateIsCorrect(date) == false)
                {
                    cout << endl << "Given date is incorrect! Date should span between 2000-01-01 and last day of current month of this year." << endl;
                    system("pause");
                }
            }
            while( HelperMethods::checkIfDateIsCorrect(date)!= true );

            cout << "Specify type of expense: ";
            item = HelperMethods::getLine();
            cout << "Enter value of that expense: ";
            cin >> userInputAmount;

            userInputAmount = HelperMethods::changeComaToDot(userInputAmount);
            amount = HelperMethods::convertStringToDouble(userInputAmount);
            expense.setAmount(amount);
            expense.setItem(item);
            expense.setDate(date);

            if(expenses.size() == 0)
            {
                expense.setId(1);
            }
            else
            {
                expense.setId(expenses.back().getId()+1);
            }
            expensesFile.addExpenseToXml(expense, userManager.getLoggedInUserId());
            expenses.push_back(expense);
        }
    }
}

double BudgetManager::checkCurrentMonthIncomes()
{
    int numberOfOccurances = 0;
    double amountIncome = 0;
    string date = "";

    vector <Income> sortedIncomes = incomes;
    sortedIncomes = Income::sortIncomesByDate(sortedIncomes);

    system("cls");

    cout << ">>>Current Month Balance<<<" << endl << endl;
    cout << "-----------------------------------------" << endl;
    cout << "            INCOMES" << endl << endl;

    for(vector <Income>::iterator itr = sortedIncomes.begin(); itr != sortedIncomes.end(); itr++)
    {
        if(HelperMethods::checkIfItsCurrentMonth(itr -> getDate()) == true)
        {
            amountIncome = amountIncome + itr -> getAmount();
            numberOfOccurances++;
            date = HelperMethods::convertIntToString(itr -> getDate());
            date = HelperMethods::changeNonDashedDateToDashed(date);
            cout << numberOfOccurances << "." << endl;
            cout << "Date: " << date << endl;
            cout << "Source of income: " << itr -> getItem() << endl;
            cout << "Amount: " << itr -> getAmount() << endl << endl;
        }
    }

    if(numberOfOccurances == 0)
    {
        cout << "No data has been provided for that time period yet." << endl;
    }
    cout << endl << "Incomes total value: " << amountIncome << endl;
    cout << endl;

    return amountIncome;
}

double BudgetManager::checkCurrentMonthExpenses()
{
    int numberOfOccurances = 0;
    double amountExpense = 0;
    string date = "";

    vector <Expense> sortedExpenses = expenses;
    sortedExpenses = Expense::sortExpensesByDate(sortedExpenses);

    cout << "-----------------------------------------" << endl;
    cout << "            EXPENSES" << endl << endl;

    numberOfOccurances = 0;

    for(vector <Expense>::iterator itr = sortedExpenses.begin(); itr != sortedExpenses.end(); itr++)
    {
        if(HelperMethods::checkIfItsCurrentMonth(itr -> getDate()) == true)
        {
            amountExpense = amountExpense + itr -> getAmount();
            numberOfOccurances++;
            date = HelperMethods::convertIntToString(itr -> getDate());
            date = HelperMethods::changeNonDashedDateToDashed(date);
            cout << numberOfOccurances << "." << endl;
            cout << "Date: " << date << endl;
            cout << "Type of expense: " << itr -> getItem() << endl;
            cout << "Amount: " << itr -> getAmount() << endl << endl;
        }
    }

    if(numberOfOccurances == 0)
    {
        cout << "No data has been provided for that time period yet." << endl;
    }
    cout << endl << "Expenses total value: " << amountExpense << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl << endl;

    return amountExpense;
}

void BudgetManager::checkCurrentMonthBalance()
{
    double amountIncome = 0, amountExpense = 0, balance = 0;
    string date = "";

    amountIncome = checkCurrentMonthIncomes();
    amountExpense = checkCurrentMonthExpenses();

    cout << "-----------------------------------------" << endl;
    cout << "Balance: " << amountIncome - amountExpense << endl;
    cout << "-----------------------------------------" << endl << endl;


    system("pause");
}

double BudgetManager::checkPreviousMonthIncomes()
{
    int numberOfOccurances = 0;
    double amountIncome = 0;
    string date = "";

    vector <Income> sortedIncomes = incomes;
    sortedIncomes = Income::sortIncomesByDate(sortedIncomes);

    system("cls");

    cout << ">>>Last Month's Balance<<<" << endl << endl;
    cout << "-----------------------------------------" << endl;
    cout << "            INCOMES" << endl << endl;

    for(vector <Income>::iterator itr = sortedIncomes.begin(); itr != sortedIncomes.end(); itr++)
    {
        if(HelperMethods::checkIfItsPreviousMonth(itr -> getDate()) == true)
        {
            amountIncome = amountIncome + itr -> getAmount();
            numberOfOccurances++;
            date = HelperMethods::convertIntToString(itr -> getDate());
            date = HelperMethods::changeNonDashedDateToDashed(date);
            cout << numberOfOccurances << "." << endl;
            cout << "Date: " << date << endl;
            cout << "Source of income: " << itr -> getItem() << endl;
            cout << "Amount: " << itr -> getAmount() << endl << endl;
        }
    }
    if(numberOfOccurances == 0)
    {
        cout << "No data has been provided for that time period yet." << endl;
    }
    cout << endl << "Incomes total value: " << amountIncome << endl;

    return amountIncome;
}

double BudgetManager::checkPreviousMonthExpenses()
{
    int numberOfOccurances = 0;
    double amountIncome = 0, amountExpense = 0, balance = 0;
    string date = "";

    vector <Expense> sortedExpenses = expenses;
    sortedExpenses = Expense::sortExpensesByDate(sortedExpenses);

    cout << "-----------------------------------------" << endl;
    cout << "            EXPENSES" << endl << endl;
    numberOfOccurances = 0;
    for(vector <Expense>::iterator itr = sortedExpenses.begin(); itr != sortedExpenses.end(); itr++)
    {
        if(HelperMethods::checkIfItsPreviousMonth(itr -> getDate()) == true)
        {
            amountExpense = amountExpense + itr -> getAmount();
            numberOfOccurances++;
            date = HelperMethods::convertIntToString(itr -> getDate());
            date = HelperMethods::changeNonDashedDateToDashed(date);
            cout << numberOfOccurances << "." << endl;
            cout << "Date: " << date << endl;
            cout << "Source of income: " << itr -> getItem() << endl;
            cout << "Amount: " << itr -> getAmount() << endl << endl;
        }
    }
    if(numberOfOccurances == 0)
    {
        cout << "No data has been provided for that time period yet." << endl;
    }
    cout << endl << "Expenses total value: " << amountExpense << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl << endl;

    return amountExpense;
}

void BudgetManager::checkPreviousMonthBalance()
{
    double amountIncome = 0, amountExpense = 0, balance = 0;
    string date = "";

    amountIncome = checkPreviousMonthIncomes();
    amountExpense = checkPreviousMonthExpenses();

    cout << "-----------------------------------------" << endl;
    cout << "Balance: " << amountIncome - amountExpense << endl;
    cout << "-----------------------------------------" << endl << endl;

    system("pause");
}

double BudgetManager::checkSpecificTimePeriodIncomes(int startingDateInt, int endingDateInt)
{
    int numberOfOccurances = 0;
    double amountIncome = 0;
    string date = "";

    vector <Income> sortedIncomes = incomes;
    sortedIncomes = Income::sortIncomesByDate(sortedIncomes);

    cout << "-----------------------------------------" << endl;
    cout << "            INCOMES" << endl << endl;
    for(vector <Income>::iterator itr = sortedIncomes.begin(); itr != sortedIncomes.end(); itr++)
    {
        if(HelperMethods::checkIfItsSelectedTimePeriod(startingDateInt, endingDateInt, itr -> getDate()) == true)
        {
            amountIncome = amountIncome + itr -> getAmount();
            numberOfOccurances++;
            date = HelperMethods::convertIntToString(itr -> getDate());
            date = HelperMethods::changeNonDashedDateToDashed(date);
            cout << numberOfOccurances << "." << endl;
            cout << "Date: " << date << endl;
            cout << "Source of income: " << itr -> getItem() << endl;
            cout << "Amount: " << itr -> getAmount() << endl << endl;
        }
    }
    if(numberOfOccurances == 0)
    {
        cout << "No data has been provided for that time period yet." << endl;
    }
    cout << endl << "Incomes total value: " << amountIncome << endl;

    return amountIncome;
}

double BudgetManager::checkSpecificTimePeriodExpenses(int startingDateInt, int endingDateInt)
{
    int numberOfOccurances = 0;
    double amountExpense = 0;
    string date = "";

    vector <Expense> sortedExpenses = expenses;
    sortedExpenses = Expense::sortExpensesByDate(sortedExpenses);

    cout << "-----------------------------------------" << endl;
    cout << "            EXPENSES" << endl << endl;
    numberOfOccurances = 0;

    for(vector <Expense>::iterator itr = sortedExpenses.begin(); itr != sortedExpenses.end(); itr++)
    {
        if(HelperMethods::checkIfItsSelectedTimePeriod(startingDateInt, endingDateInt, itr -> getDate()) == true)
        {
            amountExpense = amountExpense + itr -> getAmount();
            numberOfOccurances++;
            date = HelperMethods::convertIntToString(itr -> getDate());
            date = HelperMethods::changeNonDashedDateToDashed(date);
            cout << numberOfOccurances << "." << endl;
            cout << "Date: " << date << endl;
            cout << "Source of income: " << itr -> getItem() << endl;
            cout << "Amount: " << itr -> getAmount() << endl << endl;
        }
    }
    if(numberOfOccurances == 0)
    {
        cout << "No data has been provided for that time period yet." << endl;
    }
    cout << endl << "Expenses total value: " << amountExpense << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl << endl;

    return amountExpense;
}

void BudgetManager::checkSpecificTimePeriodBalance()
{
    int startingDateInt = 0, endingDateInt = 0;
    double amountIncome = 0, amountExpense = 0, balance = 0;
    string startingDate = "", endingDate = "";

    do
    {
        system("cls");
        cout << "Please select starting point of balance sheet according to yyyy-mm-dd: ";
        startingDate = HelperMethods::getLine();
        startingDate = HelperMethods::changeDashedDateToNonDashed(startingDate);
        startingDateInt = HelperMethods::convertStringToInt(startingDate);

        if(HelperMethods::checkIfDateIsCorrect(startingDateInt) == false)
        {
            cout << endl << "Given date is incorrect! Date should span between 2000-01-01 and last day of current month of this year." << endl;
            system("pause");
        }
    }
    while(HelperMethods::checkIfDateIsCorrect(startingDateInt)!= true);

    do
    {
        system("cls");
        cout << "Please select ending point of balance sheet according to yyyy-mm-dd: ";
        endingDate = HelperMethods::getLine();
        endingDate = HelperMethods::changeDashedDateToNonDashed(endingDate);
        endingDateInt = HelperMethods::convertStringToInt(endingDate);

        if(HelperMethods::checkIfDateIsCorrect(endingDateInt) == false)
        {
            cout << endl << "Given date is incorrect! Date should span between 2000-01-01 and last day of current month of this year." << endl;
            system("pause");
        }
    }
    while(HelperMethods::checkIfDateIsCorrect(endingDateInt)!= true);

    cout << endl;
    cout << ">>> " << "Selected period balance sheet from " << HelperMethods::changeNonDashedDateToDashed(startingDate) << " to " << HelperMethods::changeNonDashedDateToDashed(endingDate)
         << " <<<" << endl << endl;

    amountIncome = checkSpecificTimePeriodIncomes(startingDateInt, endingDateInt);
    amountExpense = checkSpecificTimePeriodExpenses(startingDateInt, endingDateInt);

    cout << "-----------------------------------------" << endl;
    cout << "Balance: " << amountIncome - amountExpense << endl;
    cout << "-----------------------------------------" << endl << endl;

    system("pause");
}

void BudgetManager::changePassword()
{
    userManager.changePassword();
}

int BudgetManager::logout()
{
    incomes.clear();
    expenses.clear();

    return 0;
}

int BudgetManager::exit()
{
    return -1;
}
