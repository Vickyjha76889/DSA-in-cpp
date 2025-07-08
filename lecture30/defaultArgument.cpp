#include<iostream>
using namespace std;
int print(int arr[] , int size , int start = 0){
    for(int i = start; i< size; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int num = 5;
    print(arr,num, 2);
}