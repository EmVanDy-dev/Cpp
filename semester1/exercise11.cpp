#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
class LinkedList{
    Node* head;
    public:
    LinkedList(){
        head = NULL;
    }
    void insert_begine(int data){
        Node* newNode = new Node(data);
        if(head==NULL){
            head = newNode;
            head->prev = NULL;
            return;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void display(){
        Node* temp = head;
        while (temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
   void displayBackwork(){
         Node* temp = head;
         Node* tail;
         while (temp!=NULL)
         {
            tail = temp;
            temp=temp->next;
         }
       
       while (tail != NULL)
       {
          cout<<tail->data<<" ";
          tail = tail ->prev;
       }
       cout<<endl;
   }
    void reverse(){
        Node* current = head ;
        Node * temp;
        while (current!=NULL)
        {
            temp = current->prev;
            current->prev = current->next;
            current->prev = temp;
            current = current->prev;
        }
        if(current!=NULL){
            head = current->prev;
        }
    }
    void reverse1()
    {
    Node* temp = NULL;
    Node* current = head;
    while (current != NULL) 
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        head = temp->prev;
}

};
int main(){
    LinkedList link;
    int n;
    link.insert_begine(1);
    link.insert_begine(2);
    link.insert_begine(3);
    link.insert_begine(5);
    link.display();
    link.displayBackwork();
    link.reverse1();
    cout<<"after revers "<<endl;
    link.display();
    cin>>n;
    return 0;
}