/* Cpp code to clear the clear ith bit */

#include <iostream>
using namespace std;

int clearIthBit(int num, int i)
{
    return num & ~(1 << i);
}

int main()
{
    int num;
    cout << "Enter the number:";
    cin >> num;
    int i;
    cout << "Enter the position of bit to be cleared:";
    cin >> i;
    cout << "Number after clearing the ith bit is:" << clearIthBit(num, i) << endl;
    return 0;
}