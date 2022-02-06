#ifndef HELPERMETHODS_H
#define HELPERMETHODS_H

#include <iostream>
#include <sstream>

using namespace std;

class HelperMethods
{
public:
    static string getLine();
    static string convertIntToString( int numericValue );
    static int convertStringToInt( string text );
};
#endif
