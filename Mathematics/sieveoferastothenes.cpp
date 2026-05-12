/* Cpp code to implement Sieve of Eratosthenes */

#include <iostream>
#include <vector>
using namespace std;

vector<int> sieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    for (int i = 0; i <= n; i++)
    {
        prime[i] = true;
    }
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            primes.push_back(i);
        }
    }
    return primes;
}

int main()
{
    int n;
    cout << "The Sieve of Eratosthenes is an efficient algorithm to find all prime numbers up to a given limit n." << endl;
    cout << "Enter the limit n: ";
    cin >> n;
    vector<int> primes = sieveOfEratosthenes(n);
    cout << "Prime numbers up to " << n << " are: ";
    for (int prime : primes)
    {
        cout << prime << " ";
    }
    cout << endl;
    return 0;
}