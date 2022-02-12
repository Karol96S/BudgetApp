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
    int userId;
    vector <User> users;
    UsersFile usersFile;

    //User enterNewUserData();
    bool checkIfLoginIsTaken(string newUserLogin);
    bool checkIfPasswordIsCorrect(string password);
    int getNewUserId();

public:
    UserManager()
    {
        users = usersFile.readUsersFromFile();
    }
    void addUser();
    void logoutUser();
    int loggedInUserId;
    int loginUser();
    User getNewUserData();


};
#endif
