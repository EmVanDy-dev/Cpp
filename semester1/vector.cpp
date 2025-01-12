#include<iostream>
#include<vector>
using namespace std;
int main(){
    system("cls");
    vector<int> v1 {5,2}; //only index 2
    vector<int> v2 (5,2); // as arrat 2 has 5 element and have index 5
    vector<int> v(5); // index 5
    int n_v1 = v1.size();
    int n_v2 = v2.size();
    cout<<"The size of vector v:"<<v.size()<<endl;
    cout<<"The size of vector v1: "<<n_v1<<endl;
    cout<<"The size of vector v2: "<<n_v2<<endl;
    // check element in v1
    cout<<"Display the element in v1: ";
    for(int i=0;i<n_v1;i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    // Check element in v2
    cout<<"Display the element in v2: ";
    for(int i=0;i<n_v2;i++){
        cout<<v2[i]<<" ";
    }
    return 0;
}