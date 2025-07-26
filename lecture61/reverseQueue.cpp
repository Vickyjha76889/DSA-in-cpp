#include<iostream>
#include<queue>
#include<stack>

using namespace std;
int main(){
queue<int> q;
stack<int> s;

q.push(1);
q.push(2);
q.push(3);
q.push(4);
cout<<"original queue: ";


while(!q.empty()){
    cout<<q.front()<<" ";
    s.push(q.front());
    q.pop();
}
cout<<endl;

while(!s.empty()){
    q.push(s.top());
    s.pop();
} 
cout<<"reversed queue: ";
while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
}
cout<<endl;
return 0;


}