#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream in_stream;
    char character;
    int count, letter = 97 ;

    cout.setf(ios::left);
    cout.width(19);
    cout << "Character";
	cout << "Frequency\n\n";


    while (letter < 123) {
        in_stream.open("CountTable.cpp");
        in_stream.get(character);
        count = 0;
        while (!in_stream.eof()){
            if(character == static_cast<char>(letter)) {
                count ++;
            }
            in_stream.get(character);
        }
        cout.width(19);
        cout << static_cast<char>(letter);
	    cout << count << endl;
        letter++;
        in_stream.close();
    }
    return 0;
}
