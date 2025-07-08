#include<iostream>
using namespace std;
int main(){
    int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int row = 3;
    int col = 4;
    int start = 0;
    int end = row*col-1;
    int mid = start + (end - start)/2;
    int target = 7;
    while(start <=end){
        int element =arr[mid/4][mid%4];
        if(element == target){
            cout << "element found at index:" <<mid/4<<" "<<mid%4<<endl;
            break;
        }
        
        if(element < target){
            start = mid +1;
        }
        else{
          end =   mid -1;
        }
        mid =  start + ( end - start)/2;
    }
    return 0;
}   