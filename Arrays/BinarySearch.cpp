/* Cpp code to search an element in a sorted array using binary search*/

#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int> &v, int n, int target)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if (v[mid] == target)
            return mid;
        else if (v[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
int main()
{
    int n;
    cout << "Enter the size of the array:";
    cin >> n;
    vector<int> v;
    cout << "Enter the elements of the array(sorted):";
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    int target;
    cout << "Enter the target element:";
    cin >> target;
    cout << "The index of the target " << target << " is:" << binarySearch(v, n, target) << endl;
    return 0;
}