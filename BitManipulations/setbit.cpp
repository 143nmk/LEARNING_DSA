/* Cpp code to set the ith bit */

#include <iostream>
using namespace std;

int setIthBit(int n, int i)
{
    return n | (1 << i);
}

int main()
{
    int n, i;
    cout << "Enter the number and position of bit to be set:";
    cin >> n >> i;
    cout << "Number after setting the ith bit is:" << setIthBit(n, i) << endl;
    return 0;
}