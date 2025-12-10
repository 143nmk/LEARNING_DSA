/*
 Cpp code to demonstrate the use of ternary operator in conditional statements 
*/

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    // Using ternary operator to find the maximum of two numbers
    int max = (a > b) ? a : b;

    cout << "The maximum of " << a << " and " << b << " is " << max << endl;

    return 0;
}