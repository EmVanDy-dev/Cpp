#include<iostream>
using namespace std;
int main(){
    int number = 88;    // Declare an int variable call number 
    int & refNumber = number;   //Declare a reference (alias) to the variable number
    //Both refNumber and number refer ot the same value 
    
    cout<<"number :"<<number<<endl; //Print value of variable number (88)
    cout<<"A reference of number :"<<refNumber<<endl; // Print value of referece (88)

    refNumber = 99;  // Re-assign a new value to refNumber 
    cout<<"Re-assign a new value ot refNumber :"<<refNumber<<endl;
    cout<<"value of number also changes :"<<number<<endl; //value of number also changes (99)

    number = 55; // Re-assign a new value to number 
    cout<<"Re-assign a new value to number  :"<<number<<endl;
    cout<<"Value of refNumber also changes (55) :"<<refNumber<<endl; 
    return 0;
}