#include <iostream>

using namespace std;

int greatest_common_divisor(int m, int n);

int main()
{
    int m, n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Enter m (m<n): ";
    cin >> m;
    if (m > n)
    {
        cout << "Enter m (m<n): ";
        cin >> m;
    }
    cout << "Greatest Common Divider = " << greatest_common_divisor(m, n) << endl;
    return 0;
}

int greatest_common_divisor(int m, int n)
{
    if (m > n)
    {
        cout << "ERROR, m>n";
        exit(1);
    }
    else if (m % n == 0)
    {
        return n;
    }
    else if (m > (n - m))
    {
        return greatest_common_divisor((n - m), m);
    }
    else
    {
        return greatest_common_divisor(m, (n - m));
    }
    return 0;
}