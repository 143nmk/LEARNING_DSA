/* Cpp code to get the  ith bit for a given binary number*/

#include<iostream>
using namespace std;

int getBit(int n,int i){
    int mask=1<<i;
    return (n & mask)!=0;
}

int main(){
    int n,i;
    cout<<"Enter the number:";
    cin>>n;
    cout<<"Enter the position of bit to get (0-indexed):";
    cin>>i;
    cout<<"The "<<i<<"th bit is: "<<getBit(n,i)<<endl;
    return 0;
}