#include <iostream>
#include <typeinfo>
#include <cmath>
#include "IntegerArray.h"

using namespace std;

int main() {

    int length;
    cout << "Enter array length: ";
    cin >> length;
    while (typeid(length) != typeid(int)){
        cout << "INTEGERS ONLY" << "Enter array length: ";
        cin >> length;
    }

    int arr1[length], arr2[length];

    cout << "\n\nARRAY 1\n\n";
    input_array(arr1,length);
    cout<< "Array 1 = ";
    display_array(arr1,length);

    cout << "\n\nARRAY 2\n\n";
    input_array(arr2,length);
    cout<< "Array 2 = ";
    display_array(arr2,length);

    copy_array(arr1, arr2, length);
    cout<< "Now array 1 = ";
    display_array(arr1,length);

    cout<< "STD array 1 = " << standard_deviation(arr1, length) << endl;

    return 0;

}