#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int userId;
    string login;
    string password;
    string name;
    string surname;

public:
    void setId(int newUserId);
    void setPassword(string newUserPassword);
    void setLogin(string newUserLogin);
    void setName(string newUserName);
    void setSurname(string newUserSurname);

    int getId();
    string getPassword();
    string getLogin();
    string getName();
    string getSurname();
};
#endif
