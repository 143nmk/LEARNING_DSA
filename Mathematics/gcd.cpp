/* Cpp code to find the gcd*/

#include <iostream>
using namespace std;

int main()
{
    int n1, n2;
    cout << "Enter two numbers: ";
    cin >> n1 >> n2;
    while (n1 > 0 && n2 > 0)
    {
        if (n1 > n2)
        {
            n1 = n1 % n2;
        }
        else
            n2 = n2 % n1;
    }
    if (n1 == 0)
        cout << "GCD is: " << n2;
    else
        cout << "GCD is: " << n1;
    cout << endl;
    return 0;
}