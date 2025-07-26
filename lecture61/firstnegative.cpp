// find fist negative integer in evvery window of size k in a queue


#include<iostream>
#include<dequeue>
using namespace std;

int main(){
    int n ; // no of element;
    int k; no of element in a window
    deque<int> dq;
    vector<int> ans;
    array<int, 10> arr = {1, -2 , -3 , 4, -5, 6, -7, 8, 9, 10};
    for(int i = 0; i< k ; i++){
        dq.push_back(arr[i]);
    }
    for(int i = dq.top() ; i < n)

}