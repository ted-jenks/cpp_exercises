#include <iostream>
#include <cmath>

using namespace std;

const int m = 2, n = 3, r = 2;

void get_matrix1(int mat[m][n]);
void get_matrix2(int mat[n][r]);
void matrix_mult(int mat1[][n], int mat2[][r], int answer[m][r]);
void display_matrix1( const int arr[m][n]);
void display_matrix2( const int arr[n][r]);
void display_answer( const int arr[m][r]);


int main() {
    int mat1[m][n], mat2[n][r], answer[m][r];
    cout << "\n\n\nMATRIX 1\n\n";
    get_matrix1(mat1);
    cout << "\n\n\nMATRIX 2\n\n";
    get_matrix2(mat2);
    display_matrix1(mat1);
    cout << "X\n";
    display_matrix2(mat2);
    cout << "=\n";
    matrix_mult(mat1,mat2,answer);
    display_answer(answer);
    return 0;

}

void matrix_mult(int mat1[][n], int mat2[][r], int answer[m][r]) {
    
    int running_total = 0;
    for(int i = 0 ; i < m ; i ++) {
        for(int  k = 0 ; k < r ; k ++) {
            for(int j = 0 ; j < n ; j++ ) {
                running_total += mat1[j][i] * mat2[k][j];
            }
            answer[k][i] = running_total;
            running_total = 0;
        }
    }
}

void get_matrix1(int mat[m][n]) {
    for( int i = 0 ; i < m ; i++) {
        cout << "Type in " << n << " values for row " << i + 1 << " separated by spaces: ";
        for( int j = 0 ; j < n ; j++) {
            cin >> mat[j][i];
        }
       
    }
}

void get_matrix2(int mat[n][r]) {
    for( int i = 0 ; i < n ; i++) {
        cout << "Type in " << r << " values for row " << i + 1 << " separated by spaces: ";
        for( int j = 0 ; j < r ; j++) {
            cin >> mat[j][i];
        }
       
    }
}

void display_matrix1( const int arr[m][n]) {

    cout << endl << endl;

    for ( int i = 0 ; i < m ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
}

void display_matrix2( const int arr[n][r]) {

    cout << endl << endl;

    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < r ; j++ ) {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
}

void display_answer( const int arr[m][r]) {

    cout << endl << endl;

    for ( int i = 0 ; i < m ; i++ ) {
        for ( int j = 0 ; j < r ; j++ ) {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
}