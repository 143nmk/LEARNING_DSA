/* Cpp code to check whether a number is prime or not*/

#include <iostream>
using namespace std;

bool checkprime(int n)
{
    if (n <= 1)
    {
        return 0;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    cout << "Enter a number:";
    cin >> n;
    cout << "Is prime:" << checkprime(n) << endl;
    return 0;
}