#include<iostream>
using namespace std;
int main(){
    system("cls");
    int number = 23;
    int * pNumber ;
    pNumber = &number;
    int * pAnother = &number;
    cout<<pNumber<<endl;
    cout<<pAnother<<endl<<endl;

    int i =3;
    //A pointer to varibale i or "stores the address of i"
    int * ptr = &i;
    //A reference (or alias ) for i 
    int &ref = i;
    cout<<"The value of i :"<<i<<endl;
    cout<<"The address of i :"<<ptr<<endl;
    cout<<"A reference of i :"<<ref<<endl;
    cout<<"======================="<<endl;
    int number2 = 88;
    int *pNumber2;
    pNumber2 = &number2;
    int *pAnother2 = &number2;
    cout<<"number2 :"<<number2<<endl;
    cout<<"pNumber2 :"<<pNumber2<<endl;
    cout<<"pAnothre2 :"<<pAnother2<<endl;
    cout<<"=====================2"<<endl;
    int x = 7 ;
    int* p_x = &x;   // address of x 
    int** p_px = &p_x; // pointer ot pointer
    cout<<"x :"<<x<<endl;
    cout<<"p_x :"<<p_x<<endl;
    cout<<"p_px :"<<p_px<<endl;
    return 0;
}