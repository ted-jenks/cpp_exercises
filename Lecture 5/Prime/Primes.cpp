#include <iostream>
#include <cmath>

using namespace std;

bool small_prime(int integer);
int getnumber();

int main() {

    cout << "PRIME INTEGER CHECKER\n---------------------\n\n";
    int number = getnumber();

    while (number != 0) {
        cout << "The number is";
        if(!small_prime(number)) {
            cout << " not";
        }
        cout << " a prime number.\n\n";
        number = getnumber();
    }

}

int getnumber() {
    int number;
    cout << "Enter an integer between 1 and 1000:";
    cin >> number;
    while ( number < 0 || number > 1000 ) {
        cout << "Invalid number, please try again:";
        cin >> number;
    }

    return number;

}

bool small_prime(int integer)
{
  if (integer <= 1) 
    return false;
  int limit = sqrt(integer);
  for (int factor = 2; factor<=limit; factor++) {
    if ((integer % factor) == 0)
      return false;
  }
  return true;
}