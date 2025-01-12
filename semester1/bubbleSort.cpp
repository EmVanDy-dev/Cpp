#include<bits/stdc++.h>
using namespace std;
int main(){
    system("cls"); //To cleas the screeen in visual c++

    int max_size ,i ,j,temp,arr_size ;
    max_size = 10 ;
    int arr[max_size] ;

    // Algorithm for set size and insert element to array
    cout<<"enter the Size for Array: ";cin>>arr_size ;
    cout<<"Enter "<<arr_size<<"Array Elemnts: ";
    for(int i = 0 ;i<arr_size;i++){
        cin>>arr[i];
    }
    cout<<"Unordered array : ";
    for(i = 0;i<arr_size;i++){
        cout<<arr[i] <<" ";
    }
    cout<<endl;

    // Algorithm for bubble sort : decending 
    for(i = 0 ;i<arr_size;i++){
        for(j= 0 ;j<arr_size;j++){
            if(arr[j]<arr[i]){
                temp = arr[i] ;
                arr[i] = arr[j] ;
                arr[j] = temp;
            }
        }
    }

    // display arr after apply Algorthm for bubble sort: Descending 
    cout<<"The Decending Elements in array: ";
    for(i=0;i<arr_size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}