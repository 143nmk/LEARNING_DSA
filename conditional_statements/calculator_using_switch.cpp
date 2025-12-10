/*
 Cpp code to implement a simple calculator using switch case statements.
 The calculator performs addition, subtraction, multiplication, and division based on user input.
 input: two numbers and an operator (+, -, *, /)
 output: result of the operation
*/

#include<iostream>
using namespace std;

int main(){
    int operand1,operand2;
    char operation;
    cout<<"Enter the first operand: ";
    cin>>operand1;
    cout<<"Enter the second operand: ";
    cin>>operand2;
    cout<<"Enter the operator (+, -, *, /): ";
    cin>>operation;
    switch(operation){
        case '+':
            cout<<"Result: "<<operand1 + operand2<<endl;
            break;
        case '-':
            cout<<"Result: "<<operand1 - operand2<<endl;
            break;
        case '*':
            cout<<"Result: "<<operand1 * operand2<<endl;
            break;
        case '/':
            if(operand2 != 0){
                cout<<"Result: "<<operand1 / operand2<<endl;
            } else {
                cout<<"Error: Division by zero is not allowed."<<endl;
            }
            break;
        default:
            cout<<"Error: Invalid operator."<<endl;
    }
}