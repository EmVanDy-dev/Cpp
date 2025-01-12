#include<iostream>
using namespace std;
struct node
{
    int data;
    node *link;
};

int main(){
    system("cls");
    
    node *head , *second , *third ,*tail= NULL;
    head = (node*)malloc(sizeof(node));
    second = (node*)malloc(sizeof(node));
    third = (node*)malloc(sizeof(node));
    tail = (node*)malloc(sizeof(node));

    head->data = 12;
    head->link = second;

    second->data = 13;
    second->link = third;

    third->data = 14;
    third->link = tail;

    tail->data = 15;
    tail->link = NULL;

    // while (head != NULL)
    // {
    //     cout<<head->data<<" ";
    //     head = head->link;
    // }
    
    // Delate bigginneing element 
    node *temp_node2;
    head = head->link = second;
    temp_node2 = head;

    while (temp_node2 != NULL)
    {
        cout<<temp_node2->data<<" ";
        temp_node2 = temp_node2->link;
    }
    
}