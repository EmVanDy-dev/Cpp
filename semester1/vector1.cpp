#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    system("cls");
    vector<int> myStack;
    myStack.push_back(39);
    myStack.push_back(12);
    myStack.push_back(22);

    cout<<"The data in my stack: ";
    for(int i= 0;i<myStack.size();i++){
        cout<<myStack[i]<<endl;
    }
}