#include <iostream>
#include <windows.h>
#include <iterator>
#include "UserManager.h"

using namespace std;

class BudgetManager
{
    UserManager userManager;

public:
    int loginMenu();
    int mainMenu();
};
