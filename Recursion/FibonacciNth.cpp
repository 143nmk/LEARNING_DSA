/* Cpp code to compute the nth value in fibonacci sequence */

#include <iostream>
using namespace std;

int fibonacciNth(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fibonacciNth(n - 1) + fibonacciNth(n - 2);
}

int main()
{
    int n;
    cout << "Enter the value of n:";
    cin >> n;
    cout << "The nth fibonacci number is: " << fibonacciNth(n) << endl;
    return 0;
}