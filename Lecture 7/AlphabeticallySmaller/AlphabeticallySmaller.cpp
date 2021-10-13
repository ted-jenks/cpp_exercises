#include <iostream>
#include <cstring>

using namespace std;

bool alphabetically_smaller(char string1[], char string2[]);

const int MAXLENGTH = 100;

int main()
{
    char string1[MAXLENGTH], string2[MAXLENGTH];

    cout << "Enter string 1: ";
    cin.getline(string1, MAXLENGTH);

    cout << "Enter string 2: ";
    cin.getline(string2, MAXLENGTH);

    if (alphabetically_smaller(string1, string2))
    {
        cout << "String 1 is alphabetically smaller.\n";
    }
    else
    {
        cout << "String 2 is alphabetically smaller.\n";
    }
    return 0;
}

bool alphabetically_smaller(char string1[], char string2[])
{
    int count = 0;
    while (string1[count] != '\0' && string2[count] != '\0')
    {
        if (string1[count] < string2[count])
        {
            return true;
        }
        else if (string1[count] > string2[count])
        {
            return false;
        }
        count++;
    }
    if (string1[count] == '\0' && string2[count] != '\0')
    {
        return true;
    }
    else if (string2[count] == '\0' && string1[count] != '\0')
    {
        return false;
    }
    else
    {
        cout << "STRINGS IDENTICAL\n";
        exit(1);
    }
}