#include <iostream>
#include <cmath>
#include <typeinfo>
#include "IntegerArray.h"

using namespace std;

void input_array( int arr[], int n){
    for ( int i = 0 ; i < n ; i++ )
    {
        cout << "Enter value " << i+1 << ": ";
        cin >> arr[i];

    }

}

void display_array( const int arr[], int n ) {
    for ( int i = 0 ; i < n ; i++ )
    {
        cout << arr[i] << " ";

    }
    cout << endl << endl;
}

void copy_array( int a1[], int a2[], int n ) {
    for ( int i = 0 ; i < n ; i++ )
    {
        a1[i] = a2[i];

    }
}


double standard_deviation( const int arr[], const int n ) {
    double total = 0, mean;
    int count;
    for ( count = 0 ; count < n ; count ++ ) {
        total += static_cast<double>(arr[count]);
    }
    mean = ( total / n );
    total = 0;
    for (count = 0 ;  count < n ; count ++) {
        total += pow( (static_cast<double>(arr[count]) - mean),2);
    }

    return total/n;

}