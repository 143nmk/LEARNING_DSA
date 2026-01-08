/* Cpp code to demonstrate bitwise operators */

#include <iostream>
using namespace std;

int main()
{
    int m = 21;
    int n = 58;
    cout << "Bitwise AND of " << m << " and " << n << " is " << (m & n) << endl;
    cout << "Bitwise OR of " << m << " and " << n << " is " << (m | n) << endl;
    cout << "Bitwise XOR of " << m << " and " << n << " is " << (m ^ n) << endl;
    return 0;
}