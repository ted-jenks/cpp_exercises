#include <iostream>
#include "funcs.h"
using namespace std;


/* FUNCTION TO PRINT MESSAGE ABOUT PROGRAM FUNCTION */
void print_preliminary_message();

/* FUNCTION TO PROMPT THE USER FOR TABLE SPECS */
void input_table_specifications(int& lower, int& upper, int& step);

/* FUNCTION TO ECHO */
void print_message_echoing_input(int lower, int upper, int step);

/* FUNCTION TO PRINT TABLE */
void print_table(int lower, int upper, int step);

/* START OF MAIN PROGRAM */
int main() 
{
  cout.precision(2);                                                      
  cout.setf(ios::fixed);
  
  int lower = 0; /* the lowest Fahrenheit entry in the table */
  int upper = 0; /* the highest Fahrenheit entry in the table */
  int step = 1;  /* difference in Fahrenheit between entries */

  /* print a message explaining what the program does: */
  print_preliminary_message();
	
  /* prompt the user for table specifications in Fahrenheit: */
  input_table_specifications(lower, upper, step);
	
  /* print appropriate message including an echo of the input: */
  print_message_echoing_input(lower, upper, step);
	
  /* Print the table (including the column headings): */
  print_table(lower, upper, step);

  return 0;
}
/* END OF MAIN PROGRAM */

/* FUNCTION TO PRINT MESSAGE ABOUT PROGRAM FUNCTION */
void print_preliminary_message() {
  cout << "This program prints out a conversion table of temperatures.\n\n";
}
/* END OF FUNCTION */

/* FUNCTION TO PROMPT THE USER FOR TABLE SPECS */
void input_table_specifications(int& lower, int& upper, int& step) {
  cout << "Enter the minimum (whole number) temperature\nyou want in the table, in Fahrenheit!:";
  cin >> lower;

  cout << "Enter the maximum (whole number) temperature\nyou want in the table, in Fahrenheit!:";
  cin >> upper;

  cout << "Enter the step-size you want in the table:";
  cin >> step;
}
/* END OF FUNCTION */

/* FUNCTION TO ECHO */
void print_message_echoing_input(int lower, int upper, int step){
  cout << "\nTemperature conversion table from " << lower << " Fahrenheit \nto " << upper << ", in steps of " << step << " Fahrenheit:\n\n";
}
/* END OF FUNCTION */
  

/* FUNCTION TO PRINT TABLE */
void print_table(int lower, int upper, int step){
  cout << endl <<  "Fahrenheit" << "\t" << "Celsius" << "\t\t" << "Absolute Value" << endl << endl;
  for(double fahrenheit = lower ; fahrenheit  <= upper ; fahrenheit += step) {
    //cout << setw(15) <<  fahrenheit << setw(17) << celcius(fahrenheit) << setw(20) << kelvin(celcius(fahrenheit)) << endl;
    cout  <<  fahrenheit << "\t\t" << celsius_of(fahrenheit) << "\t\t" << absolute_value_of(fahrenheit) << endl;
  }
}
 /* END OF FUNCTION */
