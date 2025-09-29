// you have a given a question in heap where you have to find the kth smallest element in an array



#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int kSmallestElement(int arr[], int n , int k){
    priority_queue<int> pq;
    for(int i = 0 ;i<k;i++){
        pq.push(arr[i]);
    }

    for(int i = k ; i<=n;i++){
        if(pq.top() > arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans = pq.top();
    return ans;
}

int main(){
    int arr[5] = {7,10,4,20,15};
    int n = 5;
    int k = 4;
    int ans = kSmallestElement(arr,n,k);
    cout<<"the kth smallest element is : " <<ans<<endl;
}

// 📝 Explanation (step by step)

// We want the kth smallest element:

// Create a max heap of size k.

// After inserting the first k elements, the largest among them is at pq.top().

// Traverse remaining elements (i = k to n-1):

// If the current element is smaller than the heap’s largest, replace it:

// Pop the top (largest among the heap).

// Push the new element.

// This way, the heap always contains the k smallest elements seen so far.

// At the end:

// pq.top() is the largest among those k smallest → i.e., the kth smallest element overall.



// 📊 Example Walkthrough

// Array = [7, 10, 4, 20, 15], k = 4

// Push first 4 → heap = [20, 10, 7, 4] (top = 20).

// Next element = 15. Compare with top (20). Since 15 < 20:

// Pop 20, push 15 → heap = [15, 10, 7, 4].

// Now heap has the 4 smallest elements {15, 10, 7, 4},
// so top() = 15 → the 4th smallest element. ✅

// ⏱ Complexity

// Building heap of size k: O(k log k).

// Processing remaining n-k elements: O((n-k) log k).

// Total = O(n log k), space = O(k).