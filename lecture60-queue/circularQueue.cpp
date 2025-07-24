#include<iostream>
using namespace std;

class circularQueue {
    private:
        int* arr;
        int front;
        int rear;
        int size;

    public:

    circularQueue(){
        size  = 5;
        arr = new int[size];
        rear = -1;
        front = -1;
    }

    void sizeOfQueue(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
        }
        else if(rear >= front){
            cout<<"size of queue is: "<< rear - front + 1<<endl;
        }
        else{
            cout<<"size of queue is: "<< size - front + rear + 1<<endl;
        }
    }

    void queue(int data){
        if((front == 0 && rear == size -1) || ( rear == (front -1 ) % (size -1) )){ // Queue is full
            cout<<"queue is full" <<endl;
        }
        else if(front == -1){  // Queue is empty
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        else if (rear == size -1 && front != 0){  // rear is at the end and front is not at the start
            rear = 0;
            arr[rear] = data;
        }
        else{    // normal case
            rear++;
            arr[rear] = data;
        }
    }    

    int dequeue(){
        if(front == -1){ // Queue is empty
            return -1;
        }
        else if(front == rear){ // only one element
            int ans = arr[front];
            front = -1;
            rear = -1;
            return ans;
        }
        else if(front == size -1){ // rear is at the end
            int ans = arr[front];
            front = 0;
            return ans;
        }
        else{
            int ans = arr[front];  // normal case
            front++;
            return ans;
        }
    }

    void top(){
        if(front == -1){
            cout<<"queue is empty"<<endl;
        }
        else{
            cout<<"top element is: "<<arr[front]<<endl;
        }
    }
    void back(){
        if(front == -1){
            cout<<"queue is empty"<<endl;
        }
        else{
            cout<<"last element is: "<<arr[rear]<<endl;
        }
    }
};

int main(){
    circularQueue q;
    q.queue(10);
    q.top();
    q.back();
    q.queue(20);  
    q.dequeue();
    q.queue(30);  
    q.top();
    q.back();
    q.queue(20);  
    q.sizeOfQueue();


}