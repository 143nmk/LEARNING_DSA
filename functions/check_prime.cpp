/* Cpp code to check a given number is prime or not*/

#include <iostream>
using namespace std;

bool check_prime_brute(int n);
bool check_prime_optimal(int n);

int main()
{
    int n;
    cout << "Enter the number to check prime:";
    cin >> n;
    cout << check_prime_brute(n) << endl;
    cout << check_prime_optimal(n) << endl;
    return 0;
}

bool check_prime_brute(int n) // Brute force method to check prime
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i <= n - 1; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool check_prime_optimal(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}