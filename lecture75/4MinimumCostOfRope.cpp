// task is that we have n ropes of different lengths,
// we need to connect these ropes into on rope.
//  and find the minimum cost of connecting the ropes 
// the cost of connecting ropes is equal to the sum of their lengths.
#include<iostream>
#include<queue>
using namespace std;

int minCostOfRopes(int ropes[],int n){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        pq.push(ropes[i]);
    }
    int cost = 0;
    while(pq.size()>1){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        int sum = first + second;
        cost += sum;
        pq.push(sum);
    }

    return cost;
}
int main(){
    int ropes[] = {4,3,2,6};
    int n = sizeof(ropes)/sizeof(ropes[0]);
    cout<<"The minimum cost of connecting ropes is: ";
    cout<<minCostOfRopes(ropes,n);
    cout<<endl;
    return 0;
}