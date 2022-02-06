#include "UsersFile.h"

void UsersFile::saveUsersToXml(vector <User> &users)
{
    bool checkIfFileWasSaved = false;

    if(xml.FindElem("UsersData") == false)
    {
     xml.AddElem("UsersData");
    }

    xml.IntoElem();
    vector <User>::iterator itr = users.begin();

    while(itr != users.end())
    {
    string id = "";
    id = HelperMethods::convertIntToString(itr -> getId());

    xml.AddElem("userId:", id); //mozliwe ze trzeba zamienic id na string
    xml.IntoElem();
    xml.AddElem("Login:", itr -> getLogin());
    xml.AddElem("Password:", itr -> getPassword());
    xml.AddElem("Name:", itr -> getName());
    xml.AddElem("Surname:", itr ->getSurname());
    xml.OutOfElem();
    }
    xml.OutOfElem();
    checkIfFileWasSaved = xml.Save("C:\\Users\\GIGABYTE GAMING\\Desktop\\C++ projekty\\K.S. Projekty\\BudgetApplicationOOP\\users.xml");

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

    if(xml.Load("C:\\Users\\GIGABYTE GAMING\\Desktop\\C++ projekty\\K.S. Projekty\\BudgetApplicationOOP\\users.xml") == true)
    {
      xml.FindElem("UsersData");
      xml.IntoElem();

      while (xml.FindElem("userId:") == true)
      {
      idBeforeConversion = xml.GetData(); //zwraca string
      id = HelperMethods::convertStringToInt(idBeforeConversion);
      user.setId(id);

      xml.IntoElem();

      xml.FindElem("Login:");
      login = xml.GetData();
      user.setLogin(login);

      xml.FindElem("Password:");
      password = xml.GetData();
      user.setPassword(password);

      xml.FindElem("Name:");
      name = xml.GetData();
      user.setName(name);

      xml.FindElem("Surname:");
      surname = xml.GetData();
      user.setSurname(surname);

      xml.OutOfElem();
      users.push_back(user);
      }

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
}
