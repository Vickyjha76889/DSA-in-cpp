#include<iostream>

using namespace std;

void merge(int *arr , int s, int e) {

    int mid = (s+e)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayindex = s;
    for(int i = 0; i<len1;i++) {
        first[i] = arr[mainArrayindex++];
    }

    mainArrayindex = mid+1;
    for(int i = 0 ; i<len2; i++){
        second[i] = arr[mainArrayindex++];
    }

    //merge both array

    int index1 =0;
    int index2 = 0;
    mainArrayindex = s;

    while(index1<len1 and index2<len2) {
        if(first[index1]<second[index2]){
            arr[mainArrayindex++] = first[index1++];
        }
        else{
            arr[mainArrayindex++] = second[index2++];
        }
    }
    while(index1<len1) {
        arr[mainArrayindex++] = first[index1++];
    }
    while(index2<len2) {
        arr[mainArrayindex++] = second[index2++];
    }

}

void mergeSort(int *arr , int s, int e){

    if(s>=e){
        return;
    }

    int mid = (s+e)/2;

    mergeSort(arr,s,mid);   // left side

    mergeSort(arr,mid+1,e); // right side

    merge(arr,s,e);

}

int main(){

    int arr[5] = {5,2,47,3,6};
    int s = 0;
    int e =5;
    mergeSort(arr,s,e-1);

    for(int i =0 ; i<e;i++){
        cout<<arr[i]<<" ";
    }
    
}