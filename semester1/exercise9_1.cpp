#include<iostream>
using namespace std;
class Algorithm{
    public:
    int linearSum(int num);
    void linearSum2(int num);
};
int Algorithm::linearSum(int num){
    int total = 0;
    for(int i=0;i<=num;i++){
        total += i;
    }
    return total;
}
void Algorithm::linearSum2(int num){
    int total = 0;
    int total2 ;
    for(int i = 1;i<=num;i++){
        for(int j =1;j<=num;j++){
            total +=j;
        }
        total2 = total/i;
        cout<<"Total "<<i<<" :"<<total2<<endl;
    }
}
int main(){
    system("cls");
    Algorithm sum;
    int num;
    cout<<"Please enter a number :";cin>>num;
    cout<<"Total of number: "<<sum.linearSum(num)<<endl;
    sum.linearSum2(num);
    return 0;
}