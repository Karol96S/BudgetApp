#include "UserManager.h"

bool UserManager::checkIfLoginIsTaken( string newUserLogin)
{
    for(int i = 0; i < users.size(); i++)
    {
        if(users[i].getLogin() == newUserLogin)
        {
            cout << endl << "This login is already taken." << endl;
            return true;
        }
    }
    return false;
}

User UserManager::getNewUserData()
{
    User user;
    string newUserLogin;
    string newUserPassword;
    string newUserName;
    string newUserSurname;
    int newUserId = 0;

    system("cls");

    do
    {
     cout << "Enter login: ";
     cin >> newUserLogin;
     cout << endl;
     user.setLogin(newUserLogin);
    }
    while( checkIfLoginIsTaken(newUserLogin) == true );

    cout << "Enter password: ";
    cin >> newUserPassword;
    user.setPassword(newUserPassword);
    cout << endl;

    cout << "Enter your name: ";
    cin >> newUserName;
    user.setName(newUserName);
    cout << endl;

    cout << "Enter your last name: ";
    cin >> newUserSurname;
    user.setSurname(newUserSurname);
    cout << endl;

    user.setId(getNewUserId());

    return user;
}

int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

void UserManager::addUser()
{
    User user = getNewUserData();
    users.push_back(user);
    usersFile.addUserToXml(user);

    cout << "Account has been successfully registered!" << endl;
    system("pause");
}

int UserManager::loginUser()
{
    string login = "", password = "";

    cout << endl << "Enter login: ";
    cin.sync();
    login = HelperMethods::getLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int attemptsRemaining = 3; attemptsRemaining > 0; attemptsRemaining--)
            {
                cout << "Enter password (attempts remaining: " << attemptsRemaining << "): ";
                password = HelperMethods::getLine();

                if (itr -> getPassword() == password)
                {
                    loggedInUserId = itr -> getId();
                    cout << endl << "Logged in succesfully!" << endl << endl;
                    system("pause");
                    return 1;
                }
            }
            cout << "Wrong password has been entered 3 times." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "There is no user with that login" << endl << endl;
    system("pause");
    return 0;
}

void UserManager::logoutUser()
{
    loggedInUserId = 0;
}

int UserManager::getLoggedInUserId()
{
    return loggedInUserId;
}

string UserManager::getLoggedInUserName()
{
    string name = "";

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
        {
            if (itr -> getId() == loggedInUserId)
            {
                name = itr -> getName();
            }
        }
        return name;
}

void UserManager::changePassword()
{
    system("cls");

    if (loggedInUserId > 0)
    {
        string newPassword = "";
        cout << "Enter new password: ";
        newPassword = HelperMethods::getLine();

        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
        {
            if (itr -> getId() == loggedInUserId)
            {
                itr -> setPassword(newPassword);
                cout << "Password has been succesfully changed." << endl << endl;
                system("pause");
            }
        }
        usersFile.saveUsersToXml(users);
    }
    else
    {
        cout << "In order to change password, login first." << endl;
        system("pause");
    }
}
