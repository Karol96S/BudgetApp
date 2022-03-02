#include "ExpensesFile.h"

void ExpensesFile::addExpenseToXml(Expense &expense, int loggedInUserId)
{
    bool checkIfFileWasSaved = false;
    expenseXml.Load(EXPENSES_FILE_NAME+".xml");
    expenseXml.ResetPos();

    if(expenseXml.FindElem("ExpensesData") == false)
    {
        expenseXml.AddElem("ExpensesData");
    }

    else
    {
        expenseXml.FindElem("ExpensesData");
    }

    expenseXml.IntoElem();

    while(expenseXml.FindElem("Expense"))
    {
        expenseXml.FindElem("Expense");
    }
    int dateBeforeConversion = 0;
    double amountBeforeConversion = 0;
    string date = "", amount = "";
    dateBeforeConversion = expense.getDate();
    amountBeforeConversion = expense.getAmount();
    date = HelperMethods::convertIntToString(dateBeforeConversion);
    date = HelperMethods::changeNonDashedDateToDashed(date);
    amount = HelperMethods::convertDoubleToString(amountBeforeConversion);

    expenseXml.AddElem("Expense");
    expenseXml.IntoElem();
    expenseXml.AddElem("userId", loggedInUserId);
    expenseXml.AddElem("expenseId", expense.getId());
    expenseXml.AddElem("date", date);
    expenseXml.AddElem("item", expense.getItem());
    expenseXml.AddElem("amount", amount);
    expenseXml.OutOfElem();

    expenseXml.OutOfElem();
    expenseXml.ResetPos();
    checkIfFileWasSaved = expenseXml.Save(EXPENSES_FILE_NAME+".xml");

    system("cls");
    if (checkIfFileWasSaved == true)
        cout << "Data saved successfully" << endl;

    else
        cout << "Couldn't save to the file. Error has occured!" << endl;
    system("pause");
}

vector <Expense> ExpensesFile::readExpenseFromFile(int loggedInUserId)
{
    Expense expense;
    vector <Expense> expenses;
    int howManyUsers = 0;
    int id = 0, expenseId = 0, date = 0;
    double amount = 0;
    string idBeforeConversion = "", expenseIdBeforeConversion = "", dateBeforeConversion = "", amountBeforeConversion = "";
    string item = "";

    if(expenseXml.Load(EXPENSES_FILE_NAME+".xml") == true)
    {
        expenseXml.ResetPos();
        expenseXml.FindElem("ExpensesData");
        expenseXml.IntoElem();

        while (expenseXml.FindElem("Expense") == true)
        {
            expenseXml.IntoElem();
            expenseXml.FindElem("userId");
            idBeforeConversion = expenseXml.GetData();
            id = HelperMethods::convertStringToInt(idBeforeConversion);

            if (id == loggedInUserId)
            {
                expenseXml.FindElem("expenseId");
                expenseIdBeforeConversion = expenseXml.GetData();
                expenseId = HelperMethods::convertStringToInt(expenseIdBeforeConversion);
                expense.setId(expenseId);

                expenseXml.FindElem("date");
                dateBeforeConversion = expenseXml.GetData();
                dateBeforeConversion = HelperMethods::changeDashedDateToNonDashed(dateBeforeConversion);
                date = HelperMethods::convertStringToInt(dateBeforeConversion);
                expense.setDate(date);

                expenseXml.FindElem("item");
                item = expenseXml.GetData();
                expense.setItem(item);

                expenseXml.FindElem("amount");
                amountBeforeConversion = expenseXml.GetData();
                amount = HelperMethods::convertStringToDouble(amountBeforeConversion);
                expense.setAmount(amount);

                expenses.push_back(expense);
            }
            expenseXml.OutOfElem();
        }

        expenseXml.OutOfElem();
        expenseXml.ResetPos();

        if(id != 0)
        {
            cout << endl;
            cout << "Expenses have been loaded to app successfuly." << endl;
            system("pause");
        }

        else if (id == 0)
        {
            cout << endl;
            cout << "Couldn't read expenses from file." << endl;
            system("pause");
        }

    }

    else
    {
        cout << endl;
        cout << "Couldn't read expenses from file." << endl;
        system("pause");
    }

    return expenses;
}
