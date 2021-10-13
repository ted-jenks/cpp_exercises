#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream in_stream;
    char character;
    int count = 0;

    in_stream.open("PrintBack.cpp");
    in_stream.get(character);

    while (!in_stream.eof()){
        cout << character;
        count ++;
        in_stream.get(character);
    }

    cout << endl << endl << count << " characters including blanks.\n\n";

    in_stream.close();

    for( int i = count ; i > 0; i--) {   
        in_stream.open("PrintBack.cpp");
        for ( int j = i ; j > 0 ; j--) {
            in_stream.get(character);
        }
        cout << character;
        in_stream.close();
    }
    cout << endl;
    return 0;
}