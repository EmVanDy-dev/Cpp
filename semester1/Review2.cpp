#include<iostream>
using namespace std;
int fact(int num){
    if(num==0){
        return 1;
    }else{
        return num * fact(num-1);
    }
}
int main(){
    cout<<"number of fact :"<<fact(10);
    return 0;
}