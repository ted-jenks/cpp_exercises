#include <iostream>

using namespace std;

void print_pyramid(int height);
int getnumber();

int main() {
    int height;
    cout << "This program prints a 'pyramid' shape of \na specified height on the screen.\n\n";
    height = getnumber();
    print_pyramid(height);
    return 0;
}

int getnumber() {
    int number;
    cout << "Enter an integer between 1 and 30: ";
    cin >> number;
    while ( number < 1 || number > 30 ) {
        cout << "Invalid number, please try again: ";
        cin >> number;
    }

    cout << endl << endl;

    return number;

}

void print_pyramid(int height){
    int stars = 2;
    for (int i = height ; i > 0 ; i-- ) {
        for (int j = i ; j > 0 ; j-- ) {    
            cout << " ";
        }
        for (int j = stars ; j > 0 ; j-- ) {
            cout << "*";
        }
        cout << "\n";
        stars += 2 ;
    }
    cout << endl << endl;
}