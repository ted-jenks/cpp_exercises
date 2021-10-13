#include <iostream>
#include <iomanip>
using namespace std;

 

double celcius(double fahrenheit);
//Precondition: Temperature in Fahrenheit.
//Postcondition: Temperature in Celcius.

double kelvin(double celcius);
//Precondition: Temperature in Celcius.
//Postcondition: Temperature in Kelvin.


int main() {

  double min, max, stepsize;

  cout << "This program will display a temperature conversion table from Fahrenheit to Celcius and Kelvin\n";
  cout << "Please enter the max temperature in Fahrenheit:";
  cin >> max;
  cout << " Please enter the min temperature in Fahrenheit:";
  cin >> min;
  cout << "Please enter the desired step-size in Fahrenheit:";
  cin >> stepsize;

  cout.precision(2);                                                      
  cout.setf(ios::fixed);
 
  //cout << setw(15) <<  "Fahrenheit" << setw(17) << "Celcius" << setw(20) << "Absolute Value" << endl << endl;
  cout << endl <<  "Fahrenheit" << "\t" << "Celsius" << "\t\t" << "Absolute Value" << endl << endl;
  for(double fahrenheit = min ; fahrenheit  <= max ; fahrenheit += stepsize) {
    //cout << setw(15) <<  fahrenheit << setw(17) << celcius(fahrenheit) << setw(20) << kelvin(celcius(fahrenheit)) << endl;
    cout  <<  fahrenheit << "\t\t" << celcius(fahrenheit) << "\t\t" << kelvin(celcius(fahrenheit)) << endl;
  }
  return 0;
}

double celcius(double fahrenheit) {
  double celcius;
  celcius = (fahrenheit - 32) * static_cast<double>(5)/9;
  return celcius;
}

double kelvin(double celcius) {
  double kelvin;
  kelvin = celcius + 273.15;
  return kelvin;
}




