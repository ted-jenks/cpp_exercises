#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in_stream;
    char character;
    int count = 0;

    in_stream.open("CountDis.cpp");
    in_stream.get(character);

    while (!in_stream.eof())
    {
        cout << character;
        count++;
        in_stream.get(character);
    }

    cout << endl
         << endl
         << count << " characters including blanks.\n";

    in_stream.close();

    return 0;
}