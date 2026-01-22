/* Cpp code to find the target element index in a rotated sorted array using binary search */

#include <iostream>
#include <vector>
using namespace std;

int searchInRotatedSortedArray(const vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            return mid; // Target found
        }

        // Determine which side is properly sorted
        if (nums[left] <= nums[mid])
        { // Left side is sorted
            if (target >= nums[left] && target < nums[mid])
            {
                right = mid - 1; // Target is in the left side
            }
            else
            {
                left = mid + 1; // Target is in the right side
            }
        }
        else
        { // Right side is sorted
            if (target > nums[mid] && target <= nums[right])
            {
                left = mid + 1; // Target is in the right side
            }
            else
            {
                right = mid - 1; // Target is in the left side
            }
        }
    }

    return -1; // Target not found
}

int main()
{
    int n;
    cout << "Enter the size of the array:";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the elements of the array:";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int target = 0;
    cout << "Enter the target element:";
    cin >> target;
    int result = searchInRotatedSortedArray(v, target);

    if (result != -1)
    {
        cout << "Target found at index: " << result << endl;
    }
    else
    {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}