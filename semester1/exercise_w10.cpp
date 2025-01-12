#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *link;
};
class LinkList{
    private:
    node *head = NULL, *tail =NULL;
    public:
    void InsertBeginning(int num);
    void InsertIndex(int num);
    void InsertEnd(int num);
    void RemoveFist();
    void RemoveIndex(int num);
    void RemoveLastNode();
    void CheckSize();
    void Display();
    void SearchElement(int num);
};
void LinkList::InsertBeginning(int num){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = num;
    newNode->link = NULL;
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }else{
        tail->link = newNode;
        tail = newNode;
    }
}
void LinkList::Display(){   
    while (head != NULL)
    {
       cout<<head->data<<" ";
       head = head->link;
    }
    
}
int main(){
    LinkList fist;
    fist.InsertBeginning(12);
    fist.InsertBeginning(12);
    fist.InsertBeginning(112);

    fist.Display();
    return 0;
}