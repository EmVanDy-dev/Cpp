/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int number,multiplication;

    cout<<"Input the number of multiplication: ";cin>>number;

    for(int i=1;i<=10;i++){
        multiplication=i*number;
        cout<<endl<<i<<" x "<<number<<" = "<<multiplication<<endl;
    }
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int number;
    string type;

    cout<<"Enter any Number : ";cin>>number;
    if(number%2==0){
        type="EVEN";
    }else {
        type="ODD";
    }
    cout<<"The number "<<number<<" is the "<<type<<" number "<<endl;
    return 0;
}
