//  sorting of  a stack

#include<iostream>
#include<stack>
using namespace std;

void sortinserted(stack<int>& stack , int num){
    if(stack.empty() || !stack.empty() && stack.top() < num){
        stack.push(num);
        return;
    }

    int n = stack.top();
    stack.pop();

    sortinserted(stack, num);

    stack.push(n);
    
}

void sortstack(stack<int>& stack){

    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    sortstack(stack);

    sortinserted(stack , num);
    
}

int main(){
    stack<int> stack;
    stack.push(5);
    stack.push(-2);
    stack.push(9);
    stack.push(-7);
    stack.push(3);
    sortstack(stack);
    while(!stack.empty()){
        cout<<stack.top()<<" ";
        stack.pop();
        // cout<<endl;
    }

}