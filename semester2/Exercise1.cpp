#include<iostream>
using namespace std;
// Exercise 1
class Recursion{
    public:
    // Declare
    int c;
    // Exercise 1
    int PowerNoRecursion(int a,int n){  // Part A
        int result =1;
        if(n==0){
            return 1;
        }else{
            for(int i=0;i<n;i++){
                result = a * result;
            }
            return result;
        }
    }
    int PowerRecursion(int a,int n){
        if(n==0){ // 1 is base case
            return 1;
        }else{
            return a *PowerRecursion(a,n-1); // general case
        }
    }
    int ReverseNoRecursion(int num){ // Part B
        int result=0;
        while (num !=0)
        {
            int num1 = num%10;
            result = result*10 + num1; 
            num = num/10;
        }
        return result;
    }
    int ReverseRecursion(int num , int result =0){
        if(num==0){
            return result;
        }else{
            int num1 = num%10;
            result = result*10 + num1;
            return ReverseRecursion(num/10,result);
        }
    }
    // Exercise 2
    int FibonacciSerias(int index  , int a = 0 , int b=1){
        if(index == 0){ // 0 is base case 
            return 0; 
        }
        else if(index == 1){ // 1 is base case
            return 1; 
        }else{
            c = a+b;
            FibonacciSerias(index-1,b,c); // general case 
            return c;
        }
    }
    void PrintFibonacciSeries(int index){
        if(index == -1){ // -1 is base case
            return;
        }else{
            PrintFibonacciSeries(index-1); // general case
            cout<<FibonacciSerias(index)<<"\t";
        }
    }

    // Exercise 3
    string PrintText(int NumTxt , string Txt ){ // use for print text
        if(NumTxt == 0){ // base case 
            return Txt;
        }else{
            Txt +="\n"+ Txt + "\n";
            return PrintText(NumTxt-2,Txt); // general case
        }
    }
    int Summation(int num , int TotalSum = 0){
        if(num == 0){ // base case 
            return TotalSum;
        }else{
            TotalSum += num;
            return Summation(num-1 , TotalSum); // general case
        }
    }
    string total = "";
    int SelectLetter(char Letter , char LoopLetter ='A'){
        // for (char i = 'A';i<='Z';i++){
        //     cout<<i<<endl;
        // }
            // total +=LoopLetter;
            if(LoopLetter == 'Z'){
                if(Letter == LoopLetter){
                    return 1;
                }else{
                    return 0;
                }
            }else{
                if(Letter == LoopLetter){
                    return 1;
                }
            }

            LoopLetter ++;
            return SelectLetter(Letter,LoopLetter);
    }
    int CountLetter(string Letter,int LengthLetter = 26 , int TotalLetter =0){
        if(LengthLetter == -1){
            return TotalLetter;
        }else{
            if(SelectLetter(Letter[LengthLetter]) == 1){
                TotalLetter +=1;
            }
            return CountLetter(Letter,LengthLetter-1,TotalLetter);
        }
    }      
};

int main(){
    system("cls");
    Recursion section1;
    // Exercise 1
    cout<<endl<<"Power(a,n) \t\t: "<<section1.PowerNoRecursion(2,4)<<endl; // Part A
    cout<<"Recursion Power(a,n) \t: "<<section1.PowerRecursion(2,4)<<endl;
    cout<<"No Recursion Reverse \t: "<<section1.ReverseNoRecursion(379)<<endl;
    cout<<"Recursion \t\t: "<<section1.ReverseRecursion(379)<<endl;

    cout<<section1.FibonacciSerias(0)<<endl;
    cout<<section1.FibonacciSerias(1)<<endl;
    cout<<section1.FibonacciSerias(2)<<endl;
    cout<<section1.FibonacciSerias(3)<<endl;
    cout<<section1.FibonacciSerias(4)<<endl;
    cout<<section1.FibonacciSerias(5)<<endl;
    cout<<section1.FibonacciSerias(6)<<endl;
    section1.PrintFibonacciSeries(5);

    // Exercise 3
    cout<<endl;
    cout<<section1.PrintText(4,"Hello world!");
    cout<<endl;
    cout<<section1.Summation(4);
    cout<<endl;
    cout<<"Count capital letter "<<section1.CountLetter("EMVANDY");
    return 0;
}

