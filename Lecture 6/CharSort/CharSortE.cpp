/* C++ Programming, Example answer, Exercise 2, Sheet 6  */

/* Author: Rob Miller and William Knottenbelt
   Program last changed: 30th September 2001    */

/* This program demonstrates selection sort for strings */

#include <iostream>
using namespace std;

const int MAXIMUM_STRING_LENGTH = 80;

/* Function to sort a string */
void string_sort(char a[]);

/* Function which returns the index of the minimum element in 
    "a" whose index is greater than or equal "position" */
int minimum_from(char a[], int position);

/* Function to swap the values of two character variables */
void swap(char& first, char& second);

/* START OF MAIN PROGRAM */
int main()
{
	char a_string[MAXIMUM_STRING_LENGTH];
	cout << "Type in a string: ";
	cin.getline(a_string,MAXIMUM_STRING_LENGTH);
	string_sort(a_string);
	cout << "The sorted string is: " << a_string << "\n";
		
	return 0;
}
/* END OF MAIN PROGRAM */

/* DEFINITION OF FUNCTION "string_sort" */
void string_sort(char a[])
{
	int count = 0;
	
	while (a[count] != '\0')
	{
		swap(a[count],a[minimum_from(a,count)]);
		count++;
	}
}
/* END OF FUNCTION DEFINITION */

/* DEFINITION OF FUNCTION "minimum_from" */
int minimum_from(char a[], int position)
{
	int min_index = position;
	int count = position + 1;
	while (a[count] != '\0')
	{
		if (a[count] < a[min_index])
			min_index = count;
		count++;
	}
			
	return min_index;
}
/* END OF FUNCTION DEFINITION */

/* DEFINITION OF FUNCTION "swap" */
void swap(char& first, char& second)
{
	char temp = first;
	first = second;
	second = temp;
}
/* END OF FUNCTION DEFINITION */

