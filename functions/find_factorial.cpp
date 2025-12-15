/*
 Cpp code to fin the factorial of a number n

*/

#include <iostream>
using namespace std;
int find_factorial(int); // Function Decclaration(prototype)

int main()
{
    int n;
    cout << "Enter the number to find factorial: ";
    cin >> n;
    cout << "Factorial of " << n << " is " << find_factorial(n) << endl;
    return 0;
}

int find_factorial(int n) // iterative function to find factorial
{
    int result = 1;
    if (n == 0 || n == 1)
    {
        return result;
    }
    for (int i = 2; i <= n; i++)
    {
        result = result * i;
    }
    return result;
}