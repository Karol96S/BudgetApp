#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "User.h"
#include "HelperMethods.h"

using namespace std;

class UsersFile
{
    CMarkup xml;
public:
    UsersFile()
    {
       vector <User> readUsersFromFile();
    }
    void saveUsersToXml(vector <User> &users);
    vector <User> readUsersFromFile(); //postaraj sie usunac, jest juz w konstruktorze
};
#endif
