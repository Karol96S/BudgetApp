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
    cout << endl;
    cout << "Your choice: ";
    cin >> userChoice;

    if(userChoice == 1)
    {
        return userManager.loginUser();
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

/*int BudgetManager::mainMenu()
{
    int userChoice = 0;

    system("cls");
    cout << "-----------------------------------" << endl;
    cout << "           MAIN MENU" << endl;
    cout << "-----------------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Check current month's balance" << endl;
    cout << "4. Check previous month's balance" << endl;
    cout << "5. Check specified date's balance" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Logout" << endl;
    cout << "------------------------------------" << endl;
    cout << "Your choice: ";
    cin >> userChoice;

    /*switch(userChoice)
    {
case 1:

    }*/
