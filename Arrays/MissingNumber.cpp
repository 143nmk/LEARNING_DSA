/* Cpp code to find the missing number in the array given */

#include <iostream>
#include <vector>
using namespace std;
int missingNumber1(vector<int> &v, int n)
{
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum += v[i];
    }
    return ((n * (n + 1)) / 2 - sum);
}

int missingNumber2(vector<int> &v, int n)
{
    int xor1 = 0;
    int xor2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        xor1 = xor1 ^ (i + 1);
        xor2 = xor2 ^ v[i];
    }
    xor1 = xor1 ^ (n);
    return xor1 ^ xor2;
}
int main()
{
    int n;
    cout << "Enter the size of array:";
    cin >> n;
    vector<int> v(n - 1);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n - 1; i++)
    {
        cin >> v[i];
    }
    int ans = missingNumber1(v, n);
    cout << "The missing value is(from procedure 1): " << ans << endl;
    ans = missingNumber2(v, n);
    cout << "The missing value is(from procedure 2): " << ans << endl;
    return 0;
}