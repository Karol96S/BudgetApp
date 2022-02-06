#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <iterator>
#include "User.h"
#include "HelperMethods.h"

using namespace std;

class UserManager
{
    int userId;
    vector <User> users;

    //User enterNewUserData();
    bool checkIfLoginIsTaken(string newUserLogin);
    bool checkIfPasswordIsCorrect(string password);

public:
    int loggedInUserId;

    void addUser();
    User getNewUserData();
    int loginUser();
    void logoutUser();


};
#endif
