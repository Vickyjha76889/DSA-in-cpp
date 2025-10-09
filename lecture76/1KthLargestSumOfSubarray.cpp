// in this question we have to find the kth largest sum of contigous subarray
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void kthlargestsum(vector<int> arr,int k){ 
    priority_queue<int,vector<int>,greater<int>> minheap;
    for(int i = 0;i<arr.size();i++){
        int sum = 0;
        for(int j = i;j<arr.size();j++){
            sum+=arr[j];
            if(minheap.size()<k){
                minheap.push(sum);
            }
            else if(sum > minheap.top()){
                minheap.pop();
                minheap.push(sum);
            }
        }
    }
    if(minheap.size() < k){
        cout<<"Less than k subarrays are present"<<endl;
    }else{
        cout<<k<< "th Largest sum is " << minheap.top() <<endl;
    }
}

int main(){
    vector<int> arr = {10,20,-10,-40};
    int k = 1;
    kthlargestsum(arr,k);
    return 0;

}