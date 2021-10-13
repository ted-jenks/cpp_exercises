#include <iostream>
#include <cstring>

using namespace std;

void no_repetitions(char arr[]);
bool repeat(char a[], int count);
void shuffle(char a[], int start);


const int MAXLENGTH = 100;

int main() {
    char a[MAXLENGTH];
    cout << "Enter string: ";
    cin.getline(a,MAXLENGTH);
    no_repetitions(a);
    cout << "Nor repeats: " << a << endl;
    return 0;
}
void no_repetitions(char arr[]) {
    int count = 0;
	
	while (arr[count] != '\0')
	{
		if(repeat(arr, count)){
            shuffle(arr, count);
        }
		count++;
	}
}

bool repeat(char a[], int count) {
    for (int i = 0 ; i < count -1 ; i++) {
        if ( a[i] == a[count]) {
            return true;
        }
    }
    return false;
}

void shuffle(char a[], int start) {
	int count = start ;
	while ( a[count] != '\0')
	{
		a[count] = a[count+1];
		count++;
	}
}

