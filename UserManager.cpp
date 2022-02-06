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

    return user;
}

void UserManager::addUser()
{
    User user = getNewUserData();
    users.push_back(user);
    //tu dodaj zapis do pliku

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
