#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    int i;
    int j;

    node(int data,int row,int col){
        this->data = data;
        i = row;
        j = col;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &arrays , int k){
    priority_queue<node*,vector<node*> , compare > minheap;

    // step 1 : sare arrays k first elemets insert kardo

    for(int i = 0;i<k;i++){
        if(!arrays[i].empty()){
            node* tmp = new node(arrays[i][0],i,0);
            minheap.push(tmp);
        }
    }

    vector<int> ans;

    // step 2 : push next elements from the same array if present
    while(!minheap.empty()){
        node* tmp = minheap.top();

        ans.push_back(tmp->data);
        minheap.pop();

        int i = tmp->i;
        int j = tmp->j;

        if( j+1 <arrays[i].size() ) {
            node* next = new node(arrays[i][j+1],i,j+1);
            minheap.push(next);
        }
        delete tmp;
    }
    return ans;
}

int main(){
    vector<vector<int>> arrays = {
        {1,2,3},
        {1,4,5},
        {1,5,6},
    };

    int k = 3;
   vector<int> ans =  mergeKSortedArrays(arrays,k);
   for(int a : ans){
    cout<<a<<" ";
   }
   cout<<endl;
   return 0;
}