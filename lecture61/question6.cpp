// interleave the first half of the queue with second half 
//  i/p -> 11,12,13,14,15,16,17,18;
//  o/p -> 11,15,12,16,13,17,14,18;
// can only use one extra stack

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

queue<int> interleave(queue<int> q, int n){

    stack<int> s;

    for(int i = 0 ;i<n/2; i++){  // first half of q -> stack;  we have to do this again otherwise we get reverse value from this stack
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){  // stack -> queue
        q.push(s.top());
        s.pop();
    }

    for(int i = 0;i<n/2; i++){ // first half of q -> push in q then pop the first half
        q.push(q.front());
        q.pop();
    }

    for(int i = 0 ;i<n/2; i++){ // now first of q in stack;
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){  // now the main logic behind this
        
        q.push(s.top());
        s.pop();

        q.push(q.front());
        q.pop();
    }

    return q;

}

int main(){
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);


    int n = q.size();
    q = interleave(q,n);
    while(!q.empty()){
       cout<<q.front()<<" ";
        q.pop();
    }

}