/* Cpp code to count the number of ways to tile the floor */

#include <iostream>
using namespace std;

int tiling(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return tiling(n - 1) + tiling(n - 2);
}

int main()
{
    int x, n;
    cout << "Enter the values of x and n:";
    cin >> x >> n;
    cout << "The total number of ways are:" << tiling(n) << endl;
}