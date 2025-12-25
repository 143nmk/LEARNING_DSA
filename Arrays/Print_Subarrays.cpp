/* Cpp code to print all the subarrays for the given arrays 
 Brute Force Approach
 Time Complexity: O(n^3)
 Space Complexity: O(1)

*/

#include<iostream>
using namespace std;

void printSubarrays(int arr[], int n){
    for(int i=0;i<n;i++){               // starting index
        for(int j=i;j<n;j++){           // ending index
            for(int k=i;k<=j;k++){      // printing elements from starting to ending index
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }
}

int  main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    printSubarrays(arr,n);
    
    return 0;
}