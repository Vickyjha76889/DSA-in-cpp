// merge two heaps

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void mergeHeaps(priority_queue<int> &pq1 , priority_queue<int> & pq2){
    while(!pq2.empty()){
        pq1.push(pq2.top());
        pq2.pop();
    }
}

int main(){
    priority_queue<int> pq1;
    priority_queue<int> pq2;
    vector<int> v1 = {10,5,6,2};
    vector<int> v2 = {12,7,9};
    while(!v1.empty()){
        pq1.push(v1.back());
        v1.pop_back();
    }
    while(!v2.empty()){
        pq2.push(v2.back());
        v2.pop_back();
    }
    mergeHeaps(pq1,pq2);
    while(!pq1.empty()){
        cout<<pq1.top()<<" ";
        pq1.pop();
    }
    

}

