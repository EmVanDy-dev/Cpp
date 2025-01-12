#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }
    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class Linkedlist
{
    Node *head;

public:
    Linkedlist()
    {
        head = NULL;
    }
    void insert_end(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void insert_begine(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void remove_front()
    {
        if (head->next == NULL)
        {
            return;
        }
        head = head->next;
    }

    void remove_end()
    {
        if (head->next == NULL)
        {
            return;
        }
        Node *temp = head;
        Node *newNode = head;
        int i = 0;
        while (temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }
        int j = 0;
        while (j < i - 1)
        {
            newNode = newNode->next;
            j++;
        }
        newNode->next = nullptr;
    }

    // insert biginning
    // insert index
    void Insert_index(int index, int num)
    {
        int i = 1;
        Node* newNode = new Node(num);
        Node* temp = head;
        Node* fist = NULL;
        if(head==NULL){
            head = newNode;
            return;
        }
        if(index==0){
            head = newNode;
        }else{
            while (temp->next !=NULL && i<index)
            {
                fist = temp;
                temp=temp->next;
                i++;
            } 
            if(temp->next != nullptr){
                fist=temp;
                temp=temp->next;
                fist->next = newNode;
                newNode->next = temp;  
            } else{
                temp->next = newNode;
            }
        }
    }
    void printList() 
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "List empty" << endl;
            return;
        }
        cout << "Elements of the list are: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    // remove index
    void remove_index(int index)
    {
        int i = 0;
        Node *temp = head;
        Node *temp2 = head;
        Node *newNode;

        if (index == 0)
        {
            head = head->next;
        }
        else
        {

            while (temp->next != NULL && i < index)
            {
                newNode = temp;
                temp = temp->next;
                i++;
            }
            if (temp->next != NULL)
            {
                temp = temp->next;
                newNode->next = temp;
            }
            else if (temp->next == NULL)
            {
                remove_end();
            }
            else
            {
                cout << "out of range";
            }
        }
    }
    // check size
    void check_size()
    {
        Node *temp = head;
        int i = 1;
        while (temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }
        cout << "size of linkList :" << i << endl;
    }
    // Search element
    void search_element(int data)
    {
        Node *temp = head;
        int i = 0;
        while (temp->next != nullptr)
        {
            if (temp->data == data)
            {
                i++;
            }
            temp = temp->next;
        }
        if (i == 0)
        {
            cout << "No value!" << endl;
        }
        else if (i == 1)
        {
            cout << "Non dubplicated!" << endl;
        }
        else
        {
            cout << "Duplicated value!" << endl;
        }
    }
};

int main()
{
    system("cls");
    //  create lists object
    Linkedlist list;
    // insert
    list.insert_begine(21);
    list.insert_end(64);
    list.insert_end(21);
    list.insert_end(33);
    list.insert_end(84);
    // list.remove_front();
    // list.remove_end();
    // list.remove_index(4);
    list.Insert_index(5,90);
    list.printList();
    list.check_size();
    list.search_element(21);
    return 0;
}
