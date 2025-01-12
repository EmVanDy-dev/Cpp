#include<iostream>
#include<vector>
using namespace std;
class Array{
    public:
    int arr[50]={0},arr_size,element;
    int countArray=0;
    


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




    void Insert_Beginning(int num){
        for(int i=arr_size;i>=0;i--){
            arr[i+1]=arr[i];
        }
        arr[0] = num;
        cout<<"Display: ";
        for(int i=0;i<arr_size+1;i++){
            cout<<arr[i]<<" ";
        }
    }




    void Insert_ending(int num2){
                countArray=0;
            for(int i=0;i<50;i++){
            if(arr[i]!=0){
                countArray++;
            }
        }
        
        arr[countArray]=num2;

        for(int i=0;i<countArray+1;i++){
            cout<<arr[i]<<" ";
        }
    }




    void Insert_anyPosition(int position,int NewArray){
                countArray=0;
        for(int i=0;i<50;i++){
            if(arr[i]!=0){
                countArray++;
            }
        }

        for(int i=countArray-1;i>=position-1;i--){
            arr[i+1]=arr[i];
        }
        arr[position-1]=NewArray;
        
        for(int i=0;i<countArray+1;i++){
            cout<<arr[i]<<" ";
        }
    }



    void Delete_beginngin(){
                countArray=0;
            for(int i=0;i<50;i++){
            if(arr[i]!=0){
                countArray++;
            }
        }

        for(int i=0;i<countArray;i++){
            arr[i]=arr[i+1];
        }
        cout<<"\n\nDelete beginning: ";
        for(int i=0;i<countArray-1;i++){
            cout<<arr[i]<<" ";
        }
    }



    void Delete_Ending(){
                countArray=0;
            for(int i=0;i<50;i++){
            if(arr[i]!=0){
                countArray++;
            }
        }

        arr[countArray-1]=0;
        cout<<"\n\nDelete ending: ";
        for(int i=0;i<countArray-1;i++){
            cout<<arr[i]<<" ";
        }
    }



    void Delete_AnyPosition(int deleteNumber){
                countArray=0;
            for(int i=0;i<50;i++){
            if(arr[i]!=0){
                countArray++;
            }
        }
        arr[deleteNumber]=0;
        for(int i=deleteNumber;i<countArray-1;i++){
            arr[i]=arr[i+1];
        }
        cout<<"\n\nDelete position: ";
        for(int i=0;i<countArray-1;i++){
            cout<<arr[i]<<" ";
        }
    }



    void Search(int num3){
                countArray=0;
        for(int i=0;i<50;i++){
            if(arr[i]!=0){
                countArray++;
            }
        }

        int count=0;
        for(int i=0;i<countArray;i++){
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
            countArray=0;
        for(int i=0;i<50;i++){
            if(arr[i]!=0){
                countArray++;
            }
        }

        for(int i=0;i<countArray;i++){
            cout<<"\ni "<<i;
           for(int j=0 ;j<countArray;j++){
                cout<<"\tj:"<<j<<"\t"<<"arr_ind [i] "<<i<<": "<<arr[i]<<" arr_ind [j]"<<j<<": "<<arr[j]<<"\t";
               if(arr[j]<arr[i]){
                    cout<<arr[j]<<"<"<<arr[i]<<"  Trueswap("<<i<<","<<j<<")  ";
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
               }
                for(int b=0;b<countArray;b++){
                    cout<<arr[b]<<" ";
                }cout<<endl;
           }
        }
        cout<<endl;}
    //insertion sort
    void InsertionSort(){
        int index1,temp;
        vector<int> newarray(0);
        if(countArray>0){
            for(int i=0;i<countArray;i++){
                newarray[i]=arr[i];
            }
        }else{
                for(int i=0;i<arr_size;i++){ 
                newarray.push_back(arr[i]);
            }
        }
        for(int i=0;i<newarray.size();i++){
            index1=newarray[i];
            int j = i-1;
            while(j>=0&&newarray[j]>index1){
                newarray[j+1]=newarray[j];
                j--;
            }
            newarray[j+1]=index1;
        }
        cout<<endl<<"Insertion sort: ";
        for(int i=0;i<newarray.size();i++){
            cout<<newarray[i]<<" ";
        }
    }

};
int main(){
    system("cls");

    int num,num2,position,NewArray,deleteNumber,num3;
    Array array1;
    array1.Insert();

    // cout<<"\n\nInsert a new number of beginning: ";cin>>num;
    // array1.Insert_Beginning(num);


    // cout<<"\n\nInsert a new number of ending: ";cin>>num2;
    // array1. Insert_ending(num2);



    // cout<<"\n\nEnter a position: ";cin>>position;
    // cout<<"Enter New array: ";cin>>NewArray;
    // array1.Insert_anyPosition(position,NewArray);


    // array1.Delete_beginngin();



    //  array1.Delete_Ending();


    // cout<<"\n\nEnter idex that delete: ";cin>>deleteNumber;
    // array1.Delete_AnyPosition(deleteNumber-1);


    // cout<<"\n\nEnter Search Number: ";cin>>num3;
    // array1.Search(num3);

   
    //array1.Descending();

    array1.InsertionSort();

    return 0;
}

