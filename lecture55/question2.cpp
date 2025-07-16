// delete the middle element from the stack

#include<iostream>
#include<stack>
using namespace std;

void deleteMiddle(stack<int>&str , int size, int count){

    if(count == size/2){
        str.pop();
        return ;
    }
    int num = str.top();
    str.pop();

    deleteMiddle(str,size, count+1);
    str.push(num);

}

int main(){
    stack<int> str;
    str.push(1);
    str.push(2);
    str.push(3);
    str.push(4);
    str.push(5);
    int size = str.size();
    int count = 0;
    deleteMiddle(str, size, count);
    cout<<"after delete the middle element from stack ";

    while(!str.empty()){
        cout<<str.top()<<" ";
        str.pop();
    }

}