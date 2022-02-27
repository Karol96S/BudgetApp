#include "UsersFile.h"

void UsersFile::addUserToXml(User &user)
{
    xml.Load(USERS_FILE_NAME+".xml");
    bool checkIfFileWasSaved = false;

    if(xml.FindElem("UsersData") == false)
    {
     xml.AddElem("UsersData");
    }

    else
    {
        xml.FindElem("UsersData");
    }
    xml.IntoElem();

    while(xml.FindElem("User"))
    {
        xml.FindElem("User");
    }

    string id = "";
    id = HelperMethods::convertIntToString(user.getId());

    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("userId", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.OutOfElem();

    xml.OutOfElem();
    xml.ResetPos();
    checkIfFileWasSaved = xml.Save(USERS_FILE_NAME+".xml");

    system("cls");
    if (checkIfFileWasSaved == true)
    cout << "Data saved successfully" << endl;

    else
        cout << "Couldn't save to the file. Error has occured!" << endl;
    system("pause");
}

void UsersFile::saveUsersToXml(vector <User> &users)
{
    CMarkup temporaryXml;
    string id = "";
    bool checkIfFileWasSaved = false;

    temporaryXml.AddElem("UsersData");

    temporaryXml.IntoElem();
    vector <User>::iterator itr = users.begin();

    while(itr != users.end())
    {
    id = "";
    id = HelperMethods::convertIntToString(itr -> getId());

    temporaryXml.AddElem("User");
    temporaryXml.IntoElem();
    temporaryXml.AddElem("userId", id);
    temporaryXml.AddElem("Login", itr -> getLogin());
    temporaryXml.AddElem("Password", itr -> getPassword());
    temporaryXml.AddElem("Name", itr -> getName());
    temporaryXml.AddElem("Surname", itr ->getSurname());
    temporaryXml.OutOfElem();
    itr++;
    }
    temporaryXml.OutOfElem();
    checkIfFileWasSaved = temporaryXml.Save(USERS_FILE_NAME+".xml");
    temporaryXml.ResetPos();
    temporaryXml.RemoveElem();


    system("cls");
    if (checkIfFileWasSaved == true)
    cout << "Data saved successfully" << endl;

    else
        cout << "Couldn't save to the file. Error has occured!" << endl;

    system("pause");
}

vector <User> UsersFile::readUsersFromFile()
{
    User user;
    vector <User> users;
    int howManyUsers = 0;
    int id = 0;
    string idBeforeConversion = "";
    string name = "", surname = "", login = "", password = "";

    if(xml.Load(USERS_FILE_NAME+".xml") == true)
    {
      xml.FindElem("UsersData");
      xml.IntoElem();

      while (xml.FindElem("User") == true)
      {
      xml.IntoElem();
      xml.FindElem("userId");
      idBeforeConversion = xml.GetData();
      id = HelperMethods::convertStringToInt(idBeforeConversion);
      user.setId(id);

      xml.FindElem("Login");
      login = xml.GetData();
      user.setLogin(login);

      xml.FindElem("Password");
      password = xml.GetData();
      user.setPassword(password);

      xml.FindElem("Name");
      name = xml.GetData();
      user.setName(name);

      xml.FindElem("Surname");
      surname = xml.GetData();
      user.setSurname(surname);

      xml.OutOfElem();
      users.push_back(user);
      }

      xml.OutOfElem();
      xml.ResetPos();

      if(id != 0)
      {
          system("cls");
          cout << "Users have been loaded to app successfuly." << endl;
          system("pause");
      }

      else if (id == 0)
      {
          system("cls");
          cout << "Couldn't read users from file." << endl;
          system("pause");
      }

    }

    else
    {
        system("cls");
        cout << "Couldn't read users from file." << endl;
        system("pause");
    }

    return users;
}
