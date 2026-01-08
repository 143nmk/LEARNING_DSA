/* Cpp code to update the ith bit*/

#include <bits/stdc++.h>
using namespace std;

int updateBit(int n, int i, int v)
{
    n = n & ~(1 << i);
    return (n | (v << i));
}

int main()
{
    int n;
    int i;
    int v;
    cout << "Enter the number and the ith bit to be updated and the value(0 or 1): ";
    cin >> n >> i >> v;
    cout << "The original number is: " << n << endl;
    cout << "The binary representation is: " << bitset<8>(n) << endl;
    cout << "The updated number is: " << updateBit(n, i, v) << endl;
    cout << "The binary representation of the updated number is: " << bitset<8>(updateBit(n, i, v)) << endl;

    return 0;
}