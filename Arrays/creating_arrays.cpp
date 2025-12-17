/* Cpp code to create arrays  */

#include <iostream>
using namespace std;

int main()
{

    // The memory for array is allocated in a contiguous block and statically (at compile time).
    int marks[50];                     // declaration of array of size 50 i.e., can hold 50 integer values default garbage values
    int arr[5] = {11, 12, 21, 20, 23}; // declaration and initialization of array of size 5 intiallyzed with given values
    int arr1[] = {1, 2, 4};            // declaration and initialization of array of size 3 intiallyzed with given values

    // The following shows how to create an array using dynamic memory allocation
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int dynamicArray[n]; // dynamically allocated array of size n
                         // cout << sizeof(dynamicArray) << endl; // will give size of array

    int a[3] = {1}; // partial initialization, rest of the elements will be initialized to 0
    int b[3] = {0}; // all elements initialized to 0
    return 0;
}