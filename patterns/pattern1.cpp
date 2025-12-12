/*
Cpp code to print patterns
input: n
output:
1 1...  n times 
2
3 3... n times
.
.n rows
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of rows:";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}