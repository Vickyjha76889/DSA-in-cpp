#include<iostream>
using namespace std;

class deque {
    int *arr;
    int front;
    int rear;
    int size;
    public:
    deque(){
        size = 1000;
        arr = new int[size];
        front = -1;
        rear = -1;

    }

    void push_front(int x){
        
        // check if the deque is full
        if( (front == 0 && rear == size-1) || (rear == (front - 1) % (size -1)) ){
            cout << "queue is full" << endl;
        }
        else if(front == -1){  // check if deque is empty
            front = 0;
            rear = 0;
        }
        else if(front == 0){ // if single element
            front  = size -1;
        }
        else{          // normal case
            front--;
        }
        arr[front] = x; // simple addition of element at front

    }

   void push_back(int x){

    if( (front == 0 && rear == size - 1 ) ||( rear == (front -1 ) % (size -1 ) ) ){
        cout <<"queu is full"<<endl;
    }
    else if(front == -1){
        front  = rear = 0;
    }
    else if(rear == size - 1 && front != 0){
        rear = 0;
    }
    else{
        rear++;
    }
    arr[rear] = x;

   }

   int pop_front(){
    //check if the the deque is empty
    if(front == -1){
        cout<<"queue is empty"<<endl;
        return -1;
    }
    int x = arr[front];  // if the deque is not empty, we can pop at front ;
    arr[front] = -1;

    if(front == rear){  // if there is only one element
        front = -1;
        rear = -1;
    }
    else if(front == size - 1){ // if the front is at the end of the array
        front = 0;
    }
    else{                 // normal case
        front++;
    }
    return x;

   }

   int pop_back(){
    //check if the deque is empty
    if(front == -1){
        cout<<"queue is empty"<<endl;
        return -1;;
    }
    int x = arr[rear];
    arr[rear] = -1;

    if(front == rear){
        front = rear = -1;
    }
    else if(rear == 0){
        rear = size - 1;
    }
    else{
        rear--;
    }
    return x;
   }
 
   int get_front(){
    if(front == -1){
        cout<<"queue is empty"<<endl;
        return -1;
    }
    return arr[front];

   }

   int get_back(){
     if(front == -1){
        cout<<"queue is empty"<<endl;
        return -1;
    }
    return arr[rear];
    
   }

   bool is_empty(){
    if(front == -1){
        return true;
    }
    else{
        return false;
    }

   }
   bool is_full(){

    if( front == 0 && rear == size - 1 || rear == (front -1) % (size - 1) ) {
        return true;

    }
    else{
        return false;
    }

   }
};

int main(){
    deque d;
    d.push_back(10);
    d.push_back(20);    
    d.push_front(5);
    cout << d.get_front() << endl;      
    cout << d.get_back() << endl;
    d.pop_back();
    d.pop_front();
    cout << d.get_front() << endl;
    cout << d.get_back() << endl;
}