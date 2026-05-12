/* Cpp code to find prime numbers in a given range */

#include <iostream>
using namespace std;
bool checkPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

void printPrimes(int lower, int upper)
{
    while (lower <= upper)
    {
        if (checkPrime(lower))
        {
            cout << lower << " ";
        }
        lower++;
    }
}

int main()
{
    int lower, upper;
    cout << "Enter the lower and upper limits:";
    cin >> lower >> upper;
    printPrimes(lower, upper);
    cout << endl;
    return 0;
}