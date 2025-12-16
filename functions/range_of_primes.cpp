/* Cpp code to print the prime numbers from 2 to n
  input: integer n
  output: prime numbers from 2 to n
 Note: 1 is not a prime number
 Brute Force Approach
 Time Complexity: O(n*sqrt(n))
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

bool check_prime(int);

void print_primes(int);

int main()
{
    int n;
    cout << "Enter the value of n:";
    cin >> n;
    print_primes(n);
    return 0;
}

void print_primes(int n)
{
    if (n <= 1)
    {
        cout << "No prime numbers exist less than or equal to " << n << endl;
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        if (check_prime(i))
        {
            cout << i << " ";
        }
    }
    cout<<endl;
    return;
}

bool check_prime(int num)
{
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}