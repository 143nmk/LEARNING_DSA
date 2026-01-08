/* Cpp code to find the largest element in an array*/

#include<bits/stdc++.h>
using namespace std;
int largestElement(vector<int> &v){
    int max=v[0];
    int n=v.size();
    for(int i=1;i<n;i++){
        if(v[i]>max){
            max=v[i];
        }
    }
    return max;

}
int main(){
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    int largest = largestElement(v);
    cout<<"The largest element in the array is: "<<largest<<endl;
    return 0;
}