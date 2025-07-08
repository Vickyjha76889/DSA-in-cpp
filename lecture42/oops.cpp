#include<iostream>
// #include"hero.cpp"
using namespace std;

class hero{
    public:
     string name;
     int age;
     int semester;
     hero(int age){
        cout<<"this"<<this<<endl;
        this -> age = age;
        // cout<<"hello  my name is ";
     }
};

int main(){
    hero h1(10);
    // cout<<"size of "<<sizeof(h1);
    cout<<"adress is "<<&h1;
    h1.name = "vicky";
    // h1.age = 20;
    h1.semester = 2;
    cout<<h1.name<<endl;
    cout<<h1.age<<endl;
    cout<<h1.semester<<endl;


}