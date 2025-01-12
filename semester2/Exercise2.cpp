#include <bits/stdc++.h>
using namespace std;

// Singly Linked List Implementation
struct SinglyNode {
    int data;
    SinglyNode* next;
    SinglyNode(int data) : data(data), next(nullptr) {}
};

class SinglyLinkedList {
public:
    SinglyNode* head = nullptr;

    void addNode(int item) {
        SinglyNode* newNode = new SinglyNode(item);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void addFromArray(int arr[], int first_index, int last_index) {
        for (int i = first_index; i <= last_index; i++) {
            addNode(arr[i]);
        }
    }

    void swapNodes(SinglyNode* a, SinglyNode* b) {
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

    SinglyNode* partition(SinglyNode* head, SinglyNode* end, SinglyNode** newHead, SinglyNode** newEnd) {
        SinglyNode* pivot = end;
        SinglyNode* prev = nullptr;
        SinglyNode* cur = head;
        SinglyNode* tail = pivot;
        while (cur != pivot) {
            if (cur->data < pivot->data) {
                if (*newHead == nullptr) {
                    *newHead = cur;
                }
                prev = cur;
                cur = cur->next;
            } else {
                if (prev) {
                    prev->next = cur->next;
                }
                SinglyNode* temp = cur->next;
                cur->next = nullptr;
                tail->next = cur;
                tail = cur;
                cur = temp;
            }
        }
        if (*newHead == nullptr) {
            *newHead = pivot;
        }
        *newEnd = tail;
        return pivot;
    }

    SinglyNode* quickSortRec(SinglyNode* head, SinglyNode* end) {
        if (!head || head == end) {
            return head;
        }

        SinglyNode* newHead = nullptr;
        SinglyNode* newEnd = nullptr;
        SinglyNode* pivot = partition(head, end, &newHead, &newEnd);

        if (newHead != pivot) {
            SinglyNode* temp = newHead;
            while (temp->next != pivot) {
                temp = temp->next;
            }
            temp->next = nullptr;
            newHead = quickSortRec(newHead, temp);
            temp = getTail(newHead);
            temp->next = pivot;
        }

        pivot->next = quickSortRec(pivot->next, newEnd);
        return newHead;
    }

    void quickSort() {
        SinglyNode* tail = getTail(head);
        head = quickSortRec(head, tail);
    }

    SinglyNode* getTail(SinglyNode* node) {
        while (node != nullptr && node->next != nullptr) {
            node = node->next;
        }
        return node;
    }

    void printList() {
        SinglyNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Doubly Linked List Implementation
struct DoublyNode {
    int data;
    DoublyNode* next;
    DoublyNode* prev;
    DoublyNode(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    DoublyNode* head = nullptr;
    DoublyNode* tail = nullptr;

    void addNode(int item) {
        DoublyNode* newNode = new DoublyNode(item);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addFromArray(int arr[], int first_index, int last_index) {
        for (int i = first_index; i <= last_index; i++) {
            addNode(arr[i]);
        }
    }

    void swapNodes(DoublyNode* a, DoublyNode* b) {
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

    DoublyNode* partition(DoublyNode* low, DoublyNode* high) {
        int pivot = high->data;
        DoublyNode* i = low->prev;

        for (DoublyNode* j = low; j != high; j = j->next) {
            if (j->data <= pivot) {
                i = (i == nullptr) ? low : i->next;
                swapNodes(i, j);
            }
        }
        i = (i == nullptr) ? low : i->next;
        swapNodes(i, high);
        return i;
    }

    void quickSort(DoublyNode* low, DoublyNode* high) {
        if (low != nullptr && high != nullptr && low != high && low != high->next) {
            DoublyNode* pivot = partition(low, high);
            quickSort(low, pivot->prev);
            quickSort(pivot->next, high);
        }
    }

    void printList() {
        DoublyNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    DoublyNode* getTail(DoublyNode* node) {
        while (node != nullptr && node->next != nullptr) {
            node = node->next;
        }
        return node;
    }
};

void swap(int arr[], int pos1, int pos2) {
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int partition(int arr[], int first_index, int last_index, int pivot) {
    int i = first_index;
    int j = first_index;
    while (i <= last_index) {
        if (arr[i] > pivot) {
            i++;
        } else {
            swap(arr, i, j);
            i++;
            j++;
        }
    }
    return j - 1;
}

void quickSort(int arr[], int first_index, int last_index) {
    if (first_index < last_index) {
        int pivot = arr[last_index];
        int pos = partition(arr, first_index, last_index, pivot);

        quickSort(arr, first_index, pos - 1);
        quickSort(arr, pos + 1, last_index);
    }
}

int main() {
    int arr[8] = {8, 15, 4, 3, 18, 7, 1, 4};

    // Part 1: Array Operations
    swap(arr, 2, 6);
    for (int i = 0; i < 8; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Part 2: Array QuickSort
    partition(arr, 0, 7, arr[7]);
    quickSort(arr, 0, 7);
    for (int i = 0; i < 8; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << "====SinglyLinkedList====" << endl;

    // Singly Linked List
    SinglyLinkedList list1;
    list1.addFromArray(arr, 0, 7);
    list1.quickSort();
    list1.printList();

    cout << endl << "====DoublyLinkedList====" << endl;

    // Doubly Linked List
    DoublyLinkedList list2;
    list2.addFromArray(arr, 0, 7);
    DoublyNode* tail = list2.getTail(list2.head);
    list2.quickSort(list2.head, tail);
    list2.printList();

    return 0;
}
