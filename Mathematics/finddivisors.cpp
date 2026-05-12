/* Cpp code to find all the divisors of  a number */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> divisors;
    cout << "Enter a  number: ";
    cin >> n;
    cout << "The divisors of " << n << " are: ";
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
            if (n / i != i)
            {
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    for (int it : divisors)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}