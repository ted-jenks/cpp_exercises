#include <iostream>
using namespace std;

int main() {
  int running = 1, number, exp, exporiginal;
  
  cout << "Enter number:";
  cin >> number;

  cout << "Enter exponent:";
  cin >> exp;

  exporiginal = exp;

  for (exp = exp ; exp > 0 ; exp--) {
    running = running * number;
  }

  cout << number << "^" << exporiginal << " = " << running << endl;

  return 0;
}
