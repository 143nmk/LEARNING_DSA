/* Cpp code to remove the duplicates from the  sorted array in inplace*/

#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int> &v, int n)
{
    int i = 0;
    int j = 1;
    while (j < n)
    {
        if (v[i] != v[j])
        {
            v[++i] = v[j];
        }
        j++;
    }
    return i;
}
int main()
{
    int n;
    cout << "Enter the size of the array:";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the elements of the array in sorted:";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int size = removeDuplicates(v, n);
    cout << "After removing the duplciates:" << endl;
    for (int i = 0; i <= size; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}