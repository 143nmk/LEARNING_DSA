/* Cpp code to find the number that appear onces in an array */

#include <iostream>
#include <vector>
using namespace std;

int appearingOnce(vector<int> &v, int n)
{
    int xor1 = 0;
    for (int i = 0; i < n; i++)
    {
        xor1 ^= v[i];
    }
    return xor1;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the elements of the array:";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int ans = appearingOnce(v, n);
    cout << "The number that appears once is: " << ans << endl;
    return 0;
}