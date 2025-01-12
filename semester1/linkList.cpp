#include<iostream>
using namespace std;
struct node
{
    int data ;
    node *next ;
};
class link_list{
    private:
    node *head,*tail;
    public:
    link_list(){
        head = NULL;
        tail = NULL;
    }
};

int main(){
    link_list myList ;

    node *head , *tail = NULL;
    head = (node*)malloc(sizeof(node));
    tail = (node*)malloc(sizeof(node));

    head->data = 36;
    head->next = tail;

    tail->data = 38 ;
    tail->next = NULL;

    while (head !=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    
    return 0;
}