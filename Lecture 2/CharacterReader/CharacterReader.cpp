#include <iostream>
using namespace std;

int main() {
  char letter;
  int number;

  cout << "Enter a letter and press RETURN:";
  cin >> letter;

  number = letter;

  if (number >= 65 && number <= 90) {
    cout << "The lower case character corresponding to  " << letter << " is " << char (letter + 32);
  }
  else if (number >= 97 && number <= 122) {
    cout << "The upper case character corresponding to  " << letter << " is " << char (letter - 32);
  }
  else {
    cout << letter << " is not a letter";
  }

  cout << endl;
  
  return 0;
}
      
