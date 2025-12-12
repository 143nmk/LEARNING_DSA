/* 
 Cpp code to print first N natural numbers using loops

  input: N
  output:print first N natural numbers

*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number:";
    cin>>n;
    cout<<"Printing natural numbers using for loop:";
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Printing natural numbers using while loop:";
    int i=1;
    while(i<=n){
        cout<<i<<" ";
        i++;
    }
    cout<<endl;
    cout<<"Printing natural numbers using do-while loop:";
    i=1;
    do{
        cout<<i<<" ";
        i++;
    }while(i<=n);
    cout<<endl;
    return 0;
}