#include<iostream>
#include<queue>
using namespace std;

int main() {
    deque<int> q;

    q.push_front(20);
    q.push_back(10);

    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
}