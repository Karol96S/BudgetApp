#include "HelperMethods.h"

string HelperMethods::getLine()
{
    string line = "";
    getline(cin, line);
    return line;
}

int HelperMethods::convertStringToInt( string text )
{
    int textToInt;
    istringstream iss(text);
    iss >> textToInt;

    return textToInt;
}

string HelperMethods::convertIntToString( int numericValue)
{
    ostringstream ss;
    ss << numericValue;
    string str = ss.str();

    return str;
}
