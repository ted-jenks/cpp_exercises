#include <iostream>
#include <string>

using namespace std;


void string_sort(char a[]);
	
int minimum_from(char a[], int position);
	
void swap(char& first, char& second);

void display_array( const char arr[], int n );

const int MAXLENGTH = 100;

int main() {
    char string1[MAXLENGTH];

    for (int i=0 ; i < MAXLENGTH ; i++) {
        string1[i] = ' ';
    }


    cout << "Enter string: ";
    cin.getline(string1,MAXLENGTH);

    string_sort(string1);
    cout << "Sorted string: ";
    display_array(string1, MAXLENGTH);


    return 0;

}

void display_array( const char arr[], int n ) {
    for ( int i = 0 ; i < n ; i++ )
    {
        cout << arr[i];

    }
    cout << endl << endl;
}


void string_sort(char a[])
{
    for (int count = 0 ; count < MAXLENGTH - 1 ; count ++) {
        cout << a[count] << endl;
		swap(  a[count]  ,  a[minimum_from(a,count)]  );
    }
}
	
int minimum_from(char a[], int position)
{
    for (int i=0 ; i < MAXLENGTH ; i++) {
        if ( a[i] == ' ' ) {
            a[i] = '|';
        }
        
    }
	int min_index = position;
    for (int count = position + 1 ; count < MAXLENGTH - 1; count ++) {
        if (static_cast<int>(a[count]) < static_cast<int>(a[min_index]))

			min_index = count;
    }

    for (int i=0 ; i < MAXLENGTH ; i++) {
        if ( a[i] == '|' ) {
            a[i] = ' ';
        }
        
    }

	return min_index;
}
	
void swap(char& first, char& second)
{
	char temp = first;
	first = second;
	second = temp;
}