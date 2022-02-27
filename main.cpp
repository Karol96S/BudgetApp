#include <iostream>
#include "BudgetManager.h"

using namespace std;

int main()
{
    int userChoice = 0;
    BudgetManager budgetManager("users","incomes","expenses");

    while(userChoice != -1)
    {
        userChoice = budgetManager.loginMenu();

        if(userChoice == 1)
        {
            while(userChoice != -1 && userChoice != 0)
            {
                userChoice = budgetManager.mainMenu();
                if(userChoice == -1)
                {
                    break;
                    return 0;
                }
            }
        }
    }

    return 0;
}
