#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <cstdio>
#include "Markup.h"
#include "User.h"
#include "HelperMethods.h"

using namespace std;

class UsersFile
{
    CMarkup xml;
    const string USERS_FILE_NAME;

public:
    UsersFile(string usersFileName) : USERS_FILE_NAME(usersFileName){}

    void saveUsersToXml(vector <User> &users);
    void addUserToXml(User &user);
    vector <User> readUsersFromFile();
};
#endif
