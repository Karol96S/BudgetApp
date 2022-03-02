#include "HelperMethods.h"

string HelperMethods::getLine()
{
    cin.sync();

    string line = "";
    getline(cin, line);

    return line;
}

int HelperMethods::convertStringToInt(string text)
{
    int textToInt = 0;
    istringstream iss(text);
    iss >> textToInt;

    return textToInt;
}

string HelperMethods::convertIntToString(int numericValue)
{
    ostringstream ss;
    ss << numericValue;
    string str = ss.str();

    return str;
}

double HelperMethods::convertStringToDouble(string userInputAmount)
{
    double userInputAsDouble = stod(userInputAmount);
    return userInputAsDouble;
}

string HelperMethods::convertDoubleToString(double amount)
{
    string amountAsString = "";
    amountAsString = to_string(amount);
    return amountAsString;
}

int HelperMethods::getNumber()
{
    cin.sync();

    string input = "";
    int number = 0;

    while(true)
    {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "Invalid input. Enter listed value. " << endl;
    }
    return number;
}

int HelperMethods::getTodaysDate()
{
    int date = 0;
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y%m%d");
    auto str = oss.str();
    date = convertStringToInt(str);

    return date;
}

int HelperMethods::getNumberOfDaysInAMonth(int month, int year)
{
    //leap year condition, if month is 2
	if( month == 2)
	{
		if((year%400==0) || (year%4==0 && year%100!=0))
			return 29;
		else
			return 28;
	}
	//months which has 31 days
	else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
	||month == 10 || month==12)
		return 31;
	else
		return 30;
}

bool HelperMethods::checkIfDateIsCorrect(int date)
{
   int beginInterval = 20000101;
   int endInterval = getTodaysDate();
   int endIntervalMonth = 0, endIntervalYear = 0;
   int dateDays = 0, dateMonth = 0, dateYear = 0;
   int correctNumberOfDaysInAMonth = 0;

   endIntervalYear = (endInterval - (endInterval % 10000)) / 10000;
   endIntervalMonth = (endInterval - endIntervalYear*10000 - (endInterval % 100)) / 100;

   endInterval = endInterval - (endInterval % 100 );
   endInterval = endInterval + getNumberOfDaysInAMonth(endIntervalMonth, endIntervalYear);

   if (date >= beginInterval && date <= endInterval)
   {
       dateYear = (date - (date % 10000))/10000;
       dateDays = date % 100;
       dateMonth = (date - dateYear*10000 - (dateDays))/100;
       correctNumberOfDaysInAMonth = getNumberOfDaysInAMonth(dateMonth, dateYear);

       if( dateDays <= correctNumberOfDaysInAMonth && dateDays >= 01 && dateMonth <= 12 && dateMonth >= 01)
       {
           return true;
       }

       else
       {
           return false;
       }
   }

   else
   {
    return false;
   }

}

string HelperMethods::changeDashedDateToNonDashed(string dateString)
{
    string date = "";
    for (int i = 0; i < dateString.length(); i++)
    {
        if (dateString[i] != '-')
        {
            date = date + dateString[i];
        }
    }
    return date;
}

string HelperMethods::changeNonDashedDateToDashed(string dateNonDashed)
{
    string date = "";
    for (int i = 0; i < dateNonDashed.length(); i++)
    {
        date = date + dateNonDashed[i];
        if (i == 3 || i == 5)
        {
            date = date + "-";
        }
    }
    return date;
}

string HelperMethods::changeComaToDot(string userInputAmount)
{
    string amount = "";
    for(int i = 0; i < userInputAmount.length(); i++)
    {
        if(userInputAmount[i] != ',')
        {
        amount = amount + userInputAmount[i];
        }

        else if(userInputAmount[i] == ',')
        {
           amount = amount + ".";
        }
    }
    return amount;
}

bool HelperMethods::checkIfItsCurrentMonth(int date)
{

   int todaysDate = getTodaysDate();
   int todaysDateMonth = 0, todaysDateYear = 0;

   todaysDateYear = (todaysDate - (todaysDate % 10000)) / 10000;
   todaysDateMonth = (todaysDate - todaysDateYear*10000 - (todaysDate % 100)) / 100;

   int dateToCheck = date;
   int dateToCheckMonth = 0, dateToCheckYear = 0;

   dateToCheckYear = (dateToCheck - (dateToCheck % 10000)) / 10000;
   dateToCheckMonth = (dateToCheck - dateToCheckYear*10000 - (dateToCheck % 100)) / 100;

   if(todaysDateMonth == dateToCheckMonth && todaysDateYear == dateToCheckYear)
   {
       return true;
   }

   else
    return false;
}

bool HelperMethods::checkIfItsPreviousMonth(int date)
{
   int todaysDate = getTodaysDate();
   int todaysDateMonth = 0, todaysDateYear = 0;

   todaysDateYear = (todaysDate - (todaysDate % 10000)) / 10000;
   todaysDateMonth = ((todaysDate - todaysDateYear*10000 - (todaysDate % 100)) / 100) - 1;

   int dateToCheck = date;
   int dateToCheckMonth = 0, dateToCheckYear = 0;

   dateToCheckYear = (dateToCheck - (dateToCheck % 10000)) / 10000;
   dateToCheckMonth = (dateToCheck - dateToCheckYear*10000 - (dateToCheck % 100)) / 100;

   if(todaysDateMonth == dateToCheckMonth && todaysDateYear == dateToCheckYear)
   {
       return true;
   }

   else
    return false;
}

bool HelperMethods::checkIfItsSelectedTimePeriod(int startingDateInt, int endingDateInt, int dateToCheck)
{
    if(dateToCheck >= startingDateInt && dateToCheck <= endingDateInt)
    {
        return true;
    }

    else
        return false;
}
