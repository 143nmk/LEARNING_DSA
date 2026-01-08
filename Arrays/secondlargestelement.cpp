/* Cpp code to find the second largest element in an array*/

#include<bits/stdc++.h>
using namespace std;

int secondLargestElement(vector<int> &v){
    int max=v[0];
    int secondMax=INT_MIN;
    int n=v.size();
    for(int i=1;i<n;i++){
        if(v[i]>max){
            secondMax=max;
            max=v[i];
        }
        else if(v[i]>secondMax && v[i]!=max){
            secondMax=v[i];
    }
}
    return secondMax;
}

int main(){
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    vector<int> v;
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    int secondLargest = secondLargestElement(v);
    cout<<"The second largest element in the array is: "<<secondLargest<<endl;
    return 0;
}