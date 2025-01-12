#include<bits/stdc++.h>
#include<queue>
using namespace std;
class Queue{
    public:
    queue<int> arr;
    int numSize,front,rear;

    Queue(int s) : numSize(s) , front(0) , rear(-1){

    }

    //Push
    void Push(int num){
        arr.push(num);
        front++;
    }
    void Pop(){
        cout<<"Pop arr:"<<arr.front();arr.pop();
        cout<<endl;
    }
    void Front(){
        cout<<endl<<"Front of the element: "<<arr.front()<<endl;
    }
    void Display(){
        cout<<"Display arr: ";
        while(!arr.empty() && numSize>1){
            cout<<arr.front()<<" ";
            arr.pop();
            numSize--;
        }
    }
    void Size(){
        cout<<"\nsize: "<<arr.size()<<endl;
    }
    int Back(){
        return arr.back();
    }
    int IsEmpty(){
        return arr.size()>0?false:true; 
    }
    int Isfull(){
        return numSize<0?true:false;
    }
};
int main(){
    system("cls");
    Queue queue1(5);
    queue1.Push(1);
    queue1.Push(4);
    queue1.Push(3);
    queue1.Push(8);
    queue1.Push(90);
    queue1.Push(87);
    queue1.Push(1);
    queue1.Push(4);
    queue1.Push(3);
    queue1.Push(8);
    queue1.Push(90);
    queue1.Push(87);
    queue1.Front();
    queue1.Pop();
    queue1.Display();
    queue1.Size();
    cout<<"Back: "<<queue1.Back()<<endl;
    cout<<"is Empty: "<<queue1.IsEmpty()<<endl;
    cout<<"is full: "<<queue1.Isfull();
    return 0;
}