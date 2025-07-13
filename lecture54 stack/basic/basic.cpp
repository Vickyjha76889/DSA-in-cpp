#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    cout<<"size of the stack is : "<<s.size()<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
        cout<<endl;

    }
}