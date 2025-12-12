/*
Cpp code to print patterns
input: n(=3)
output:
  * * *
  * *
  * 
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of rows:";
    cin>>n;
    //Method 1
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i;j--){
            cout<<"* ";
        }
        cout << endl;
    }
    //Method 2
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout<<"* ";
        }
        cout << endl;
    }
    return 0;
}