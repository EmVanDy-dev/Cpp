#include<iostream>
using namespace std;
#define Max 1000 //max size for stack
class Stack{
    protected:
    int top;
    public:
    int myStack[Max];//stack arry
    Stack(){
        top = -1;
    }
    bool push(int x);
    int pop();
    bool isEmpty();
    void display_stack();
};
//pushes element on to the stack
bool Stack::push(int item){
    if(top >=(Max -1)){
        cout<<"Stack Overflow!!!";
        return false;
    }else {
        myStack[++top] = item;
        cout<<item<<endl;
        return true;
    }
}
//remove or pops elemnts out of the stack
int Stack::pop(){
    if(top<0){
        cout<<"Stack Underflow!!";
        return 0;
    }else {
        int item = myStack[top--];
        return item;
    }
}
//check if stack is empty
bool Stack::isEmpty(){
    return (top<0);
}
void Stack::display_stack(){
    for(int i= top;i>=0;i--){
        cout<<myStack[i]<<" ";
    }
}
int main(){
    system("cls");
    class Stack mystack_2;
    cout<<"The stack push: "<<endl;
    mystack_2.push(2);
    mystack_2.push(4);
    mystack_2.push(6);

    cout<<"The data in my stack: ";
    mystack_2.display_stack();

    mystack_2.pop();
    cout<<endl;
    cout<<"After pop, the data in my stack: ";
    mystack_2.display_stack();
    return 0;
}