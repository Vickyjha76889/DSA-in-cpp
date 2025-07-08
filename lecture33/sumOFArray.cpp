#include <iostream>

using namespace std;

int sumOfArray(int arr[], int size) {

    if( size == 0 || size ==1){
        return 0 ;
    }
    
    return arr[0] + sumOfArray(arr +1 , size - 1 );

}

int main(){

    int arr[6] = {1,2,3,4,5,6};
    int size = 6;
    int add = sumOfArray( arr , size );
    cout<<add;

}