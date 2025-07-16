#include<iostream>
#include<stack>
using namespace std;

class Stack{
    public:
    int* arr;
    int top;
    int size;

    Stack(int size){
        this ->size = size;
        arr = new int[size];
        top = -1;

    }

     void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"stack overflow";
        }
     }

     void pop(){
        if(top >= 0){
            top--;

        }else{
            cout<<"stack underflow\n";
        }
     }

     int peek(){
        if(top>=0){
            return arr[top];
        }else{
            cout<<"stack is empty\n";
            return -1;
        }
     }

     bool isempty(){
        if(top == -1){
            return true;
        }else{
            return false;
        }
     }
};

int main(){
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout << "Top element is: " << st.peek() << endl;
   
    while(!st.isempty()){
        cout<<"popped "<< st.peek() <<endl;
        st.pop();
    }

    if(st.isempty()){
        cout<<"stack is empty";
    }else{
        cout<<"stack is not empty";
    }

    return 0;
}
