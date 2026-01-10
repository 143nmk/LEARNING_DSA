/* Cpp code to check the array is sorted or not*/

#include<iostream>
using namespace std;
bool checkSorted(int *a,int n){
    for(int i=1;i<n;i++){
        if(a[i-1]>a[i]){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array:";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Is array sorted:"<<checkSorted(a,n)<<endl;
    return 0;
}

