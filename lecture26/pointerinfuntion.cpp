#include<iostream>
using namespace std;
void print(int *p){
cout<<*p<<endl;
p = p + 10;
// cout<<*p<<endl;
}
int main(){
    int s = 5;
    int *p = &s;
    cout<<"before update"<<p<<endl;
    print(p);
    cout<<*p<<endl;
    cout<<"after update"<<p<<endl;;
}