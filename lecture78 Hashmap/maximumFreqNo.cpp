#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

void maximumFreqNo(int arr[],int n ){
    unordered_map<int,int> freq;
    int maxFreq = 0;
    int maxFreqNo = -1;
    for(int i = 0;i<n;i++){
        freq[arr[i]]++;
        if(freq[arr[i]]>maxFreq){
            maxFreq = freq[arr[i]];
            maxFreqNo = arr[i];
        }
    }

    unordered_map<int,int> :: iterator it = freq.begin();;
    while(it!=freq.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
}

int main(){
    int arr[] = {1,3,2,3,4,1,3,2,1,1,1};
    int n = sizeof(arr)/sizeof(int);
    maximumFreqNo(arr,n);
}