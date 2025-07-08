#include <iostream>
using namespace std;

bool binarySearch(int *arr, int s, int e , int k) {

    //base case
    if(s>e){
        return false;
    }
    int mid = s + (e-s)/2;

    if(arr[mid] == k){
        return true;
    }

    else if(arr[mid]<k){
        return binarySearch(arr, mid + 1 , e , k);
    }
    else{
        return binarySearch(arr, s , mid - 1 , k);
    }
}


int main(){

    int arr[5] = {1,2,3,4,5};
    int s  = 0;
    int e = sizeof(arr)/sizeof(arr[0]);
    int k = 3 ;
    bool ans = binarySearch( arr,s , e, k);
    if(ans == true){
        cout<<"present";
    }
    else{
        cout<<"not present";
    }

}