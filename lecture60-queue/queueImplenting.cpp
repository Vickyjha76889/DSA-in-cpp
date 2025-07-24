// queue implementing using array

#include <iostream>
#include<queue> // by the don't need this library now because we applied this manually
using namespace std;

class Queue{
    int* arr;
    int size;
    int qfront ;
    int rear ;

    public:

    Queue(){
        size = 1000;
        arr = new int[size];
        qfront = 0;
        rear = 0;
       
    }

    bool isempty(){
        if(qfront == rear){
            return true ;
        }
        else{
            return false ;
        }
    }

    void enqueue(int data){
       if(rear == size ){
        cout<<"size is full "<<endl ;
       }
       else{
        arr[rear] = data;
        rear++;
       }

    }

    int dequeue(){
        if(qfront == rear){
            return -1;  // Queue is empty
        }
        else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear){
                    qfront = 0;
                    rear = 0;
            }
            return ans;
        }

    }

    int front(){
        if(qfront == rear){
            return -1; // Queue is empty
        }
        else{
            return arr[qfront];
        }

    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    cout<<"is the queue empty : "<<q.isempty()<<endl;
    cout<<"front element: "<<q.front()<<endl;
    cout<<q.dequeue();
    cout<<endl;
    cout<<"front element: "<<q.front()<<endl;
    
}