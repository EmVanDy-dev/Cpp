/*#include<iostream>
using namespace std;
class Array{
    public:
    int arr[50]={0},arr_size,element;
    //Insert
    void Insert(){
        cout<<"enter the Size for Array: ";cin>>arr_size;
        cout<<"Enter "<<arr_size<<" Array Elements: ";
        for(int i=0;i<arr_size;i++){
            cin>>arr[i];
        }
        cout<<"output: ";
        for(int i=0;i<arr_size;i++){
            cout<<arr[i]<<" ";
        }
    }
    //Insert_Beginning
    void Insert_Beginning(int num){
        for(int i=arr_size;i>=0;i--){
            arr[i+1]=arr[i];
        }
        arr[0] = num;
        cout<<"Display: ";
        for(int i=0;i<arr_size+1;i++){
            cout<<arr[i]<<" ";
        }arr_size++;
    }
    //Insert_ending
    void Insert_ending(int num2){
         
        
        arr[arr_size]=num2;

        for(int i=0;i<arr_size+1;i++){
            cout<<arr[i]<<" ";
        }arr_size++;
    }
    //Insert_anyPosition
    void Insert_anyPosition(int position,int NewArray){
      
        for(int i=arr_size-1;i>=position-1;i--){
            arr[i+1]=arr[i];
        }
        arr[position-1]=NewArray;
        
        for(int i=0;i<arr_size+1;i++){
            cout<<arr[i]<<" ";
        }arr_size++;
    }
    //Delete_beginngin
    void Delete_beginngin(){

        for(int i=0;i<arr_size;i++){
            arr[i]=arr[i+1];
        }
        cout<<"\n\nDelete beginning: ";
        for(int i=0;i<arr_size-1;i++){
            cout<<arr[i]<<" ";
        }arr_size--;
    }
    //Delete_Ending
    void Delete_Ending(){

        arr[arr_size-1]=0;
        cout<<"\n\nDelete ending: ";
        for(int i=0;i<arr_size-1;i++){
            cout<<arr[i]<<" ";
        }arr_size--;
    }
    //Delete_AnyPosition
    void Delete_AnyPosition(int deleteNumber){

        arr[deleteNumber]=0;
        for(int i=deleteNumber;i<arr_size-1;i++){
            arr[i]=arr[i+1];
        }
        cout<<"\n\nDelete position: ";
        for(int i=0;i<arr_size-1;i++){
            cout<<arr[i]<<" ";
        }arr_size--;
    }
    //Search
    void Search(int num3){


        int count=0;
        for(int i=0;i<arr_size;i++){
            if(arr[i]==num3){
                count++;
            }
        }

        if(count==0 || count == 1){
            cout<<"\n\nNon_duplicate!"<<endl;
        }else if(count>1){
            cout<<"\n\nDuplicate Array!"<<endl;
        }
    }

    // bubble sort Descending array
    void Descending(){
        int temp;
        for(int i=0;i<arr_size;i++){
            cout<<"\ni "<<i;
           for(int j=0 ;j<arr_size;j++){
                cout<<"\tj:"<<j<<"\t"<<"arr_ind [i] "<<i<<": "<<arr[i]<<" arr_ind [j]"<<j<<": "<<arr[j]<<"\t";
               if(arr[j]<arr[i]){
                    cout<<arr[j]<<"<"<<arr[i]<<"  Trueswap("<<i<<","<<j<<")  ";
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
               }
                for(int b=0;b<arr_size;b++){
                    cout<<arr[b]<<" ";
                }cout<<endl;
           }
        }
        cout<<endl;}

};
int main(){
    system("cls");

    int num,num2,position,NewArray,deleteNumber,num3;
    Array array1;
    array1.Insert();

   cout<<"\n\nInsert a new number of beginning: ";cin>>num;
    array1.Insert_Beginning(num);


    cout<<"\n\nInsert a new number of ending: ";cin>>num2;
    array1. Insert_ending(num2);



    cout<<"\n\nEnter a position: ";cin>>position;
    cout<<"Enter New array: ";cin>>NewArray;
    array1.Insert_anyPosition(position,NewArray);

    array1.Delete_beginngin();

    array1.Delete_Ending();

    cout<<"\n\nEnter idex that delete: ";cin>>deleteNumber;
    array1.Delete_AnyPosition(deleteNumber-1);


    cout<<"\n\nEnter Search Number: ";cin>>num3;
    array1.Search(num3);

    array1.Descending();
    return 0;
}


#include <iostream>
#include <stack>
using namespace std;
class DynamicArrayStack{
public:
    int* arr;   // Dynamic array to store the stack elements
    int capacity;  // Maximum capacity of the stack
    int top;   // Index of the top element

public:
    // Constructor to initialize the stack
    DynamicArrayStack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;  // Stack is initially empty
    }

    // Destructor to free the dynamically allocated memory
    
    ~DynamicArrayStack() {
        delete[] arr;
    }
    
    

    // Push operation to add an element to the top of the stack
    void push(int element) {
        if (top == capacity - 1) {
            cout << "Stack Overflow: Cannot push element, stack is full.\n";
            return;
        }
        arr[++top] = element;
    }
    
    

    // Pop operation to remove the top element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow: Cannot pop element, stack is empty.\n";
            return;
        }
        --top;
    }


    // Peek/Top operation to get the value of the top element
    int peek() const {
        if (isEmpty()) {
          cerr << "Stack is empty. No top element.\n";
            return -1;  // Return a sentinel value indicating an empty stack
        }
        return arr[top];
    }
    
    

    // Size operation to get the current size of the stack
    int size() const {
        return top + 1;
    }

    // isEmpty operation to check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }


    // isFull operation to check if the stack is full
    bool isFull() const {
        return top == capacity - 1;
    }
};

int main() {
    // Creating a stack of capacity 5
    
    DynamicArrayStack stack(5);

    // Pushing elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Displaying the top element
    cout << "Top element: " << stack.peek() << "\n";

    // Displaying the size of the stack
   cout << "Size of the stack: " << stack.size() << "\n";

    // Checking if the stack is empty
   cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << "\n";

    // Checking if the stack is full
   cout << "Is stack full? " << (stack.isFull() ? "Yes" : "No") << "\n";

    // Popping elements from the stack
    stack.pop();
    stack.pop();

    // Checking if the stack is empty after popping elements
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}*/
#include <iostream>
using namespace std;
void display_array(int ar[], int n)
{
    for (int i = 0; i<n; i++)
    {
        cout << ar[i] << " ";
    }
    cout<<endl;
}
void insert_data(int arr[], int newData, int pos)
{
    int i;
    int n =sizeof(arr)/sizeof(arr[0]);
    for(i=n; i>pos; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[i] = newData;
    n++;
}
int main()
{
    // system("cls");
    int my_arr [] = {3, 2, 6, 4, 7};
    int arr_size = sizeof(my_arr)/ sizeof (my_arr[0]);
    cout<< "the current element in my array is : ";
    display_array(my_arr,arr_size);

    int newEle = 10;
    int pos = 3;
    insert_data(my_arr, newEle, pos);

    cout<<"the current element after add "<< newEle<<" to position "<< pos<< " : ";
    display_array(my_arr, arr_size);
    cout<< endl;
    return 0;

}
