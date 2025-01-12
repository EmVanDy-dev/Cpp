#include<bits/stdc++.h>
using namespace std;
class Complexity{
    public:
    int num;
    int newArray[30] ;
    
    void ConstantTime(int num);
    void LogarithmicTime(int num);
    void Linear_time(int num);
    void Quadratic_time(int arr[]);
    void Linear_time2();
};
void Complexity::ConstantTime(int num){
    cout<<"Number :"<<num<<endl;
}
void Complexity::LogarithmicTime(int num){
    int i=0;
    cout<<"Even number: ";
     while (i<=num)
     {
        cout<<i<<" ";
        i+=3;
     }
}
void Complexity::Linear_time(int num){
    cout<<"output of number:\n";
    for(int i= 0;i<=num;i++){
        cout<<i<<" ";
    }
}
void Complexity::Quadratic_time(int arr[]){
    int temp;
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(arr[i]>arr[j]){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                
                newArray[j] = arr[j];
            }else{
                newArray[i] = arr[i];
            }
        }
    }
}
void Complexity::Linear_time2(){
    cout<<"Linear time2 : ";
    for(int i=0;i<num;i++){
        cout<<newArray[i]<<" ";
    }
}
int main(){
    system("cls");
    int num;
    int numArr;
    int arr[30] = {};
    Complexity time1;
    //a
    cout<<"Please enter a number of constant time:";cin>>num;
    time1.ConstantTime(num);
    //b
    cout<<"Please enter a number of Logarithmic time:";cin>>num;
    time1.LogarithmicTime(num);
    //c
    cout<<"Please enter a number of Linear time";cin>>num;
    time1.Linear_time(num);
    //d
    cout<<"\nPlease enter size of arr :";cin>>time1.num;
    for(int i=0;i<time1.num;i++){
        cout<<"num "<<i<<" :";cin>>numArr;
        arr[i] = numArr;
    }
    time1.Quadratic_time(arr);
    time1.Linear_time2();
    return 0;
}