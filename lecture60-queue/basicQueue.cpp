#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;

    for(int  i = 0 ; i < 5 ; i++){
        q.push(i);
    }
    q.empty() ? cout << "queue is empty" : cout << "queue is not empty"<<endl;
    cout<< "size of queue: " << q.size() <<endl;
    for(int i = 0 ; i <5 ;i++){
        cout <<q.front() <<" ";
        q.pop() ;
    }
    cout<<endl;

    
     for(int  i = 0 ; i < 5 ; i++){
        q.push(i);
    }

    q.empty() ? cout << "queue is empty" : cout << "queue is not empty"<<endl;
    cout<< "size of queue: " << q.size() <<endl;
    for(int i = 0 ; i <5 ;i++){
        cout <<q.back() <<" ";
        q.pop() ;
    }
    cout<<endl;

    cout<< "\nafter popping, size of queue: "<<q.size() <<endl;
    q.empty() ? cout << "Queue is empty" : cout << "Queue is not empty" << endl;
    return 0;
}