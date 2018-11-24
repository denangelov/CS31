#include <iostream>
using namespace std;

int factorial(int n)
{
    int prod = 1;
    for (int i = 2; i <= n; i++)
        prod *= i;
    return prod;
}

int main()
{
    for (int k = 1; k <= 6; k++)
        cout << "The factorial of " << k << " is " << factorial(k) << endl;
}