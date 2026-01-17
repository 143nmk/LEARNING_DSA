/* Cpp code to compute the power of x raised to the power of n */

#include <iostream>
#include <vector>
using namespace std;

int powerFunction(int x, int n)
{
    if (n == 0)
        return 1;
    if (x == 0)
        return 0;
    int result = powerFunction(x, n / 2);
    result = result * result;
    if (n % 2 != 0)
    {
        return x * result;
    }
    return result;
}

int main()
{
    int x, n;
    cout << "Enter the values of x and n:";
    cin >> x >> n;
    cout << "The result is: " << powerFunction(x, n) << endl;
    return 0;
}