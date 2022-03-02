#include "IncomesFile.h"

void IncomesFile::addIncomeToXml(Income &income, int loggedInUserId)
{
    bool checkIfFileWasSaved = false;
    incomeXml.Load(INCOMES_FILE_NAME+".xml");
    incomeXml.ResetPos();

    if(incomeXml.FindElem("IncomesData") == false)
    {
        incomeXml.AddElem("IncomesData");
    }

    else
    {
        incomeXml.FindElem("IncomesData");
    }

    incomeXml.IntoElem();

    while(incomeXml.FindElem("Income"))
    {
        incomeXml.FindElem("Income");
    }
    int dateBeforeConversion = 0;
    double amountBeforeConversion = 0;
    string date = "", amount = "";
    dateBeforeConversion = income.getDate();
    amountBeforeConversion = income.getAmount();
    date = HelperMethods::convertIntToString(dateBeforeConversion);
    date = HelperMethods::changeNonDashedDateToDashed(date);
    amount = HelperMethods::convertDoubleToString(amountBeforeConversion);

    incomeXml.AddElem("Income");
    incomeXml.IntoElem();
    incomeXml.AddElem("userId", loggedInUserId);
    incomeXml.AddElem("incomeId", income.getId());
    incomeXml.AddElem("date", date);
    incomeXml.AddElem("item", income.getItem());
    incomeXml.AddElem("amount", amount);
    incomeXml.OutOfElem();

    incomeXml.OutOfElem();
    incomeXml.ResetPos();
    checkIfFileWasSaved = incomeXml.Save(INCOMES_FILE_NAME+".xml");

    system("cls");
    if (checkIfFileWasSaved == true)
        cout << "Data saved successfully" << endl;

    else
        cout << "Couldn't save to the file. Error has occured!" << endl;
    system("pause");
}

vector <Income> IncomesFile::readIncomeFromFile(int loggedInUserId)
{
    Income income;
    vector <Income> incomes;
    int howManyUsers = 0;
    int id = 0, incomeId = 0, date = 0;
    double amount = 0;
    string idBeforeConversion = "", incomeIdBeforeConversion = "", dateBeforeConversion = "", amountBeforeConversion = "";
    string item = "";

    if(incomeXml.Load(INCOMES_FILE_NAME+".xml") == true)
    {
        incomeXml.ResetPos();
        incomeXml.FindElem("IncomesData");
        incomeXml.IntoElem();

        while (incomeXml.FindElem("Income") == true)
        {
            incomeXml.IntoElem();
            incomeXml.FindElem("userId");
            idBeforeConversion = incomeXml.GetData();
            id = HelperMethods::convertStringToInt(idBeforeConversion);

            if (id == loggedInUserId)
            {
                incomeXml.FindElem("incomeId");
                incomeIdBeforeConversion = incomeXml.GetData();
                incomeId = HelperMethods::convertStringToInt(incomeIdBeforeConversion);
                income.setId(incomeId);

                incomeXml.FindElem("date");
                dateBeforeConversion = incomeXml.GetData();
                dateBeforeConversion = HelperMethods::changeDashedDateToNonDashed(dateBeforeConversion);
                date = HelperMethods::convertStringToInt(dateBeforeConversion);
                income.setDate(date);

                incomeXml.FindElem("item");
                item = incomeXml.GetData();
                income.setItem(item);

                incomeXml.FindElem("amount");
                amountBeforeConversion = incomeXml.GetData();
                amount = HelperMethods::convertStringToDouble(amountBeforeConversion);
                income.setAmount(amount);

                incomes.push_back(income);
            }
            incomeXml.OutOfElem();
        }

        incomeXml.OutOfElem();
        incomeXml.ResetPos();

        if(id != 0)
        {
            system("cls");
            cout << "Incomes have been loaded to app successfuly." << endl;
        }

        else if (id == 0)
        {
            system("cls");
            cout << "Couldn't read incomes from file." << endl;
        }

    }

    else
    {
        system("cls");
        cout << "Couldn't read incomes from file." << endl;
    }

    return incomes;
}
