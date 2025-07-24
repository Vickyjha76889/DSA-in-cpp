#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {1,2,3,4,5};
    queue<int> q;
    // q.push_range(v);
    for( int x : v){
        q.push(x);
    }

    for(int i = 0; i<5 ; i++){
        cout<<q.front()<<" ";
        q.pop();
    }

}