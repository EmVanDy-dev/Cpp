/*#include<bits/stdc++.h>
using namespace std;
double max_two(double i,double b){
    return i>b ? i:b;
}
int main(){
    double x=234.98,y=93.8;
    cout<<"maximum number between "<<x<<" and "<<y<<" is : "<<max_two(x,y)<<endl;
    return 0;
}*/

//ex:2
/*#include<bits/stdc++.h>
using namespace std;
int Factorial(int x){
    int total=1;
    for(int i=1;i<=x;i++){
        total = i*total;
    }
    return total;
}
int main(){
    cout<<Factorial(5)<<endl;
    return 0;
}*/

//ex:3

/*#include<bits/stdc++.h>
#define pi 3.14
using namespace std;
class Circle {
    private:
    double radius;
    public:
    Circle(double x){
        radius=x;
    };
    double circle_area(){
        return 2*pi*radius;
    }
    double circumference(){
        return pi*radius*radius;
    }
};
int main(){
    Circle circle(23.0);
    cout<<"circle's area: "<<circle.circle_area()<<endl;
    cout<<"circumference: "<<circle.circumference()<<endl;
    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
class infomRUPP{
    public:
    string facultyScience[6] = {"Faculty of Science","Faculty of Social Science and Humanities","Faculty of Engineering","Faculty of Deverlopment","Faculty of Education","Institutes of Foreign Languages"};
    char input[6] = {'a','b','c','d','e','f'};
    infomRUPP(){
        cout<<endl<<endl;
        for(int i=0;i<6;i++){
            cout<<input[i]<<" = "<<facultyScience[i]<<" , ";
        }
        cout<<endl<<endl;
    }
    void rupp(char letter){
        switch (letter){
            case 'a':
                cout<<"Faculty of Science"<<endl<<"(6 Departments)"<<endl;
            break;
            case 'b':
                cout<<"Faculty of Social Science and Humanities"<<endl<<"(11 Departments)"<<endl;
                break;
            case 'c':
                cout<<"Faculty of Engineering"<<endl<<"(3 Departments)"<<endl;
                break;
            case 'd':
                cout<<"Faculty of Demelopment Studies"<<endl<<"(3 Departments)"<<endl;
                break;
            case 'e':
                cout<<"Faculty of Education"<<endl<<"(3 Departments)"<<endl;
                break;
            case 'f':
                cout<<"Institutes of Foreign Languages"<<endl<<"(6 Departments)"<<endl;
                break;
        }
    }
};
int main(){
    infomRUPP info;
    char letter;
    cout<<"\nWhich one do you want: ";cin>>letter;
    cout<<endl<<endl;
    info.rupp(letter);
    cout<<endl<<endl;
    return 0;
} 