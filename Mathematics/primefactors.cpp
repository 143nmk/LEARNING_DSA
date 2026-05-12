/* cpp code to find the prime factors of a number*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<int> primeFactors;
    cout << "Enter a number:";
    cin >> n;
    cout << "The prime factors of " << n << " are: ";
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            primeFactors.push_back(i);
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }
    if (n > 1)
    {
        primeFactors.push_back(n);
    }
    for (int factor : primeFactors)
    {
        cout << factor << " ";
    }
    cout << endl;
    return 0;
}