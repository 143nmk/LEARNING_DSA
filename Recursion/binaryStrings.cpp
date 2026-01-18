/* Cpp code to form a binary strings without consecutive ones */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void binaryStrings(int n, string s, int lastdigit)
{
    if (n == 0)
    {
        cout << s << endl;
        return;
    }
    if (lastdigit != 1)
    {
        binaryStrings(n - 1, s + '0', 0);
        binaryStrings(n - 1, s + '1', 1);
    }
    else
    {
        binaryStrings(n - 1, s + '0', 0);
    }
}

int main()
{
    int n;
    cout << "Enter the value n:";
    cin >> n;
    binaryStrings(n, "", 0);
    return 0;
}