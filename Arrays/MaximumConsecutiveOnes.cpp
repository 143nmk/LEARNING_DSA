/* Cpp code to count the maximum consecutive ones in an array*/

#include <iostream>
#include <vector>
using namespace std;

int maximumOnes(vector<int> &v, int n)
{
    int maxi = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 1)
        {
            count++;
        }
        else
        {
            maxi = max(maxi, count);
            count = 0;
        }
    }
    return maxi;
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the elements of the array(0 or 1):";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int count = maximumOnes(v, n);
    cout << "The maximum number of consecutive ones are: " << count << endl;
    return 0;
}