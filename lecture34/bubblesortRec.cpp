#include<iostream>

using namespace std;

int sortArray(int *arr, int n ) {

    if(n ==0 || n==1) { // base case
        return 0;
    }

    for(int i = 0; i<n-1; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }

    return sortArray(arr,n-1);

}


int main(){

    int arr[5] = {1,3,2,6,4};
    int n =5;
    sortArray(arr,n);

    for(int i =0; i<n;i++){
        cout<<arr[i]<<" ";
    }

}