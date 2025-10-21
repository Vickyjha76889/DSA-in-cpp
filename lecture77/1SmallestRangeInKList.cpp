#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

class node{
    public:
    int data;
    int row;
    int col;

    node(int data, int row , int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};

int ksorted(vector<vector<int>> &a , int k , int n){
    priority_queue<node*,vector<node*>,compare> minheap;
    int maxi = INT_MIN;
    int mini = INT_MAX;

    // create a minheap of first column elements of all the k lists
    for(int i = 0 ; i<k ;i++){
        int element = a[i][0];
        maxi = max(maxi,element);
        mini = min(mini,element);
        minheap.push(new node(element,i,0));
    }
    int start = mini ;
    int end = maxi;

    while(true){
        node* temp = minheap.top();
        minheap.pop();
        mini = temp->data;

        int row = temp->row;
        int col = temp->col;

        if((end - start) >(maxi - mini)){
            start = mini;
            end = maxi;
        }

        if(col+1 > n){   //if the next column index excess the limit stop the process
            break;
        }
        
        int element = a[row][col + 1];
        maxi = max(maxi,element);
        minheap.push(new node(element,row,col + 1));
        delete temp;

    }
    cout<<"Range start: "<<start<<" end: "<<end<<endl;
    return end - start;
    
}

int main(){
  vector<vector<int>> a = {
    {1,5,7},
    {3,6,9},
    {2,4,8},
  };
  int k = a.size();
  int n = a[0].size();
  cout<<ksorted(a,k,n);
  return 0;
    
}

