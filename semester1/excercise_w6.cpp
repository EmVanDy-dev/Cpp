#include<iostream>
#include<stack>
#include<vector>
#define Max 10
using namespace std;
class Stack{
    protected:
    int top;
    public:
    void InsertionSort(int arr);
    bool isEmpty();
    bool isFull();
};

void Stack::InsertionSort(int size){
    int num,index,j;
    vector<int>arr2;
    if(size >Max){
        size = Max;
    }
    for(int i=0;i<size;i++){
        cin>>num;
        arr2.push_back(num);
    }
    for(int i=0;i<arr2.size();i++){
        index = arr2[i];
        j=i-1;
        while(j>=0&&index<arr2[j]){
            arr2[j+1]=arr2[j];
            j--;
        }
        arr2[j+1]=index;
    }cout<<endl;
    for(int i= 0;i<arr2.size();i++){
        cout<<arr2[i]<<" ";
    }
    top = arr2.size();
    cout<<endl<<arr2.front();
    cout<<endl<<arr2.back();
}
bool Stack::isEmpty(){
    return top>0?true:false;
}
bool Stack::isFull(){
    return top==Max ? true:false;
}
int main(){
    system("cls");
    //declare
    Stack dynamic;
    stack<int>arr;
    int size,array;

    cout<<"Size array: ";cin>>size;
    cout<<"Enter array: ";dynamic.InsertionSort(size);
    cout<<endl<<dynamic.isFull();
}         