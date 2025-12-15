/* Cpp code to find the binomial coefficient given n and r
       nCr=n!/(r!(n−r)!)

There are also optimkizations that can be done to reduce the time complexity
for example we can reduce the number of multiplications by calculating
nCr = n*(n-1)*...*(n-r+1) / r!
         1. Using Pascal's triangle property
         2. Using memoization to store previously calculated values
         3. Using iterative approach to build the values from the bottom up
*/

#include <iostream>
using namespace std;

int find_factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    int fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

int find_binomial_coefficient(int n, int r)
{
    if (n < r) // nCr is not defined for n<r
    {
        return 0;
    }
    if (n == 0 || r == 0 || n == r)
    {
        return 1;
    }
    int numerator = find_factorial(n);
    int denominator = find_factorial(r) * find_factorial(n - r);
    return numerator / denominator;
}

int main()
{
    int n, r;
    cout << "Enter the values of n and r:";
    cin >> n >> r;
    cout << "The binomial coefficient " << n << "C" << r << " is: " << find_binomial_coefficient(n, r) << endl;
    ;
    return 0;
}