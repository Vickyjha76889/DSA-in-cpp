#include<iostream>
using namespace std;
bool isSorted(int arr[],int size) {
    
    //base case
    if(size == 0 || size == 1) {
        return true;
    }


    if(arr[0] > arr[1]){
        return false;
    }
    else if(arr[0] < arr[1]){
        return true;
    }
    else{
        int ans = isSorted(arr+1, size-1);
    }
 
}
int main(){
    int arr[5] = {2,4,6,8,10};
    int size = 5;
    bool ans = isSorted(arr,size);
    if (ans = true){
        cout<<"Array is Sorted";
    }
    else{
        cout<<"Array is not sorted";
    }
}