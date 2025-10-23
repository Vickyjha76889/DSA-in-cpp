// Median in a stream 
// in this question we have continuous stream of numbers coming
// we have to find median at each point of time when a new number arrives
#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

int signum(int a, int b){
    if(a==b) return 0;
    else if(a>b) return 1;
    else return -1;
}


void callMedian(int element,
    priority_queue<int>& maxheap,
    priority_queue<int, vector<int>, greater<int>>& minheap,
     int& median ){

    switch(signum(maxheap.size(),minheap.size())){
        case 0: // both heaps are of equal size
            if(element>median){  // push in minheap if element is greater than median
                minheap.push((element));
                median = minheap.top();
            }else{                    // push in maxheap
                maxheap.push(element);
                median = maxheap.top();
            }
        break;
        case 1: // maxheap has more elements
            if(element>median){
                minheap.push(element);
                median = (maxheap.top()+minheap.top())/2;

            }else{
                int temp = maxheap.top();
                maxheap.pop();
                minheap.push(temp);
                maxheap.push(element);
                median = (maxheap.top()+ minheap.top())/2;
            } 
        break;
        case -1: // minheap has more elements
            if(element > median){
                int temp = minheap.top();
                minheap.pop();
                maxheap.push(temp);
                minheap.push(element);
                median = (maxheap.top() + minheap.top()) /2;

            } else{
                maxheap.push(element);
                median = (maxheap.top() + minheap.top())/2;
            }
        break;    
    }
}

vector<int> findMedian(vector<int> &arr, int n){
    vector<int> ans;
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    int median = -1;
    for(int i = 0;i<n;i++){
        callMedian(arr[i],maxheap,minheap,median);
        ans.push_back(median);
    }
    return ans;
}

int main() {
    vector<int> arr = {5, 15, 1, 3};
    int n = arr.size();

    vector<int> medians = findMedian(arr, n);

    for (int m : medians)
        cout << m << " ";
    cout << endl;

    return 0;
}