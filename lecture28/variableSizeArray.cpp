#include<iostream>
using namespace std;
int sumArray(int *arr,int n){
    int sum = 0;
    for(int i =0;i<n;i++){
        sum += arr[i];
    }
    return sum;
}
int main(){
    int n ;
    cin>>n;
    int *arr = new int[n];

    //for taking input in  variable size array;
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }

    int ans = sumArray(arr,n);
    cout<<ans<<endl;
}