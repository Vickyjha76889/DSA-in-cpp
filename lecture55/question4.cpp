// insert a element in the bottom of the stack

#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>&str , int size){
    if(size == 0){
        str.push(1);
        return;
    }

    int ans = str.top();
    str.pop();

    insertAtBottom(str, size-1);
    str.push(ans);
}

int main(){
    stack<int> str;
    str.push(2);
    str.push(3);
    str.push(4);
    str.push(5);
    int size  = str.size();
    insertAtBottom(str,size);
    while(!str.empty()){
        cout<<str.top()<<" ";
        str.pop();
    }
}