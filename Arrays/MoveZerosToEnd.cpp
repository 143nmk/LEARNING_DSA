/* Cpp code to move the zeros to the end of the array */

#include<iostream>
#include<vector>
using namespace std;
void moveZeros(vector<int>& v,int n){
    int i=0;
    while(i<n){
        if(v[i]==0){
            break;
        }
        i++;
    }
    if(i==n) return;
    for(int j=i+1;j<n;j++){
        if(v[j]!=0){
            swap(v[i],v[j]);
            i++;
        }
    }

}
int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the elements of the array:";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    moveZeros(v,n);
    cout<<"After moving the zeros to the end:";
    for(int it:v){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}