#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Stack {
private:
    stack<string> stack1;

public:

    void Insert_Bowl(string name) {
        if(stack1.size()<=10){
            stack1.push(name);
        }else{
            cout<<"Stack is full!"<<endl;
        }
    }

    void Remove_Top_Bowl() {
        if (!stack1.empty()) {
            stack1.pop();
        }
    }

    void Check_Top_Bowl() {
        if (!stack1.empty()) {
            cout << "Top element of Stack: " << stack1.top() << endl;
        } else {
            cout << "Stack is empty" << endl;
        }
    }

    void Check_Size() {
        cout << "Size of Stack: " << stack1.size() << endl;
    }

    void Check_isEmpty(){
        if(stack1.empty()){
            cout<<"No Any Bolw!"<<endl;
        }else{
            cout<<"There are still a few bowls in Stack of Bolw!"<<endl;
        }
    }
    void Check_ifFull(){
        if(stack1.size()==10){
            cout<<"Number of bowls is up to Limit!"<<endl;
        }else{
            cout<<"Bolw is not Full!"<<endl;
        }
    }
};

int main() {
    system("cls");
    Stack element;
    element.Insert_Bowl("purple");
    element.Insert_Bowl("blue");
    element.Insert_Bowl("green");
    element.Insert_Bowl("yellow");
    element.Insert_Bowl("orang");
    element.Insert_Bowl("red");

    element.Remove_Top_Bowl();
    element.Check_isEmpty();
    element.Check_ifFull();
    element.Check_Top_Bowl();
    element.Check_Size();

    return 0;
}