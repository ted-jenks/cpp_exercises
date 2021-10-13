#include <iostream>

using namespace std;

void checkdate(int &month);
// Precondition: integer representing a month entered by user.
// Will prompt user to re-enter value if selected month is invalid.

int main()
{
  int current_year, age_now, another_year, age_year, current_month,
      birth_month, birth_year, another_month, age_month;

  // The following code gathers information from the user.

  cout << "Enter the current year then press RETURN.\n";
  cin >> current_year;

  cout << "Enter the current month (a number from 1 to 12).\n";
  cin >> current_month;

  checkdate(current_month);

  cout << "Enter your current age in years.\n";
  cin >> age_now;

  cout << "Enter the month in which you are born (a number from 1 to 12).\n";
  cin >> birth_month;

  checkdate(birth_month);

  cout << "Enter the year for which you wish to know your age.\n";
  cin >> another_year;

  cout << "Enter the month in this year.\n";
  cin >> another_month;

  checkdate(another_month);

  cout << " Testing";

  // In the following code, year an month output is calculated.

  if (current_month >= birth_month)
  {
    birth_year = current_year - age_now;
  }
  else
  {
    birth_year = current_year - age_now - 1;
  }

  if (another_month >= birth_month)
  {
    age_year = another_year - birth_year;
    age_month = another_month - birth_month;
  }
  else
  {
    age_year = another_year - birth_year - 1;
    age_month = 12 - (birth_month - another_month);
  }

  // In the following code, output is displayed in English.

  if (age_year > 150)
  {
    cout << "Sorry, you'll probably be dead in " << another_year << "!\n";
  }
  else if (age_year == 0 && age_month == 0)
  {
    cout << "You weren't born yet!";
  }
  else if (age_year < 0)
  {
    cout << "You weren't born yet!";
  }
  else
  {

    cout << "Your age in " << another_month << "/" << another_year << ": "
         << age_year;

    if (age_year == 1)
    {
      cout << " year";
    }
    else
    {
      cout << " years";
    }

    cout << " and " << age_month;

    if (age_month == 1)
    {
      cout << " month.\n";
    }
    else
    {
      cout << " months.\n";
    }
  }

  return 0;
}

void checkdate(int &month)
{
  while (month > 12 || month <= 0)
  {
    cout << "Invalid month, try again.\n";
    cin >> month;
  }
}
