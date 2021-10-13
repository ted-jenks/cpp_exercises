#include <iostream>

using namespace std;

int fibonacci(int n);

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout
        << endl
        << fibonacci(n) << endl;

    return 0;
}

int fibonacci(int n)
{
    if (n <= 0)
    {
        cout << "\nERROR, N CANNOT BE NEGATIVE\n";
        exit(1);
    }
    else if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}