#include "User.h"

void User::setId(int newUserId)
{
    if(newUserId >= 0)
    {
        userId = newUserId;
    }
}

void User::setLogin(string newUserLogin)
{
    login = newUserLogin;
}

void User::setPassword(string newUserPassword)
{
    password = newUserPassword;
}

void User::setName(string newUserName)
{
    name = newUserName;
}

void User::setSurname(string newUserSurname)
{
    surname = newUserSurname;
}

int User::getId()
{
    return userId;
}

string User::getPassword()
{
    return password;
}

string User::getLogin()
{
    return login;
}

string User::getName()
{
    return name;
}

string User::getSurname()
{
    return surname;
}
