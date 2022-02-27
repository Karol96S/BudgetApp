#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <iterator>
#include "User.h"
#include "UsersFile.h"
#include "HelperMethods.h"

using namespace std;

class UserManager
{
    vector <User> users;
    UsersFile usersFile;
    int loggedInUserId;

    bool checkIfLoginIsTaken(string newUserLogin);
    bool checkIfPasswordIsCorrect(string password);
    int getNewUserId();

public:
    UserManager(string usersFileName) : usersFile(usersFileName)
    {
        users = usersFile.readUsersFromFile();
    }

    int loginUser();
    int getLoggedInUserId();
    User getNewUserData();
    string getLoggedInUserName();
    void addUser();
    void logoutUser();
    void changePassword();


};
#endif
