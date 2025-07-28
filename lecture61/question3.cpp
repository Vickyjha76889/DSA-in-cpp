#include<iostream>
#include<deque>
#include<stack>
using namespace std;

deque<int> reverseFirstkElements(deque<int> dq, int k , int n){
    stack<int> st;
    int arr[n];

    for(int i = 0 ; i<k; i++){
        st.push(dq.front());
        dq.pop_front();
    }

    for(int i = 0; i<k; i++){
        dq.push_back(st.top());
        st.pop();
    }

    int remaining = n - k;
    for(int i =0 ; i<remaining; i++){
        dq.push_back(dq.front());
        dq.pop_front();
    }

    return dq;

    
}

int main(){
    deque<int> dq = {1,2,3,4,5,6,7,8,9};
    int k = 3;
    int n = dq.size();
    dq = reverseFirstkElements(dq,k,n);
    for(int i = 0 ; i<n ; i++){
        cout<<dq[i]<<" ";
    }
}