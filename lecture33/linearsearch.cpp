#include <iostream>

using namespace std;

bool isPresent(int arr[], int size, int key) {

    if(size == 0 || size == 1){
        return false;
    }

    bool present = false;

    if(arr[0] == key){
        return true ;
    }
    else{
         return isPresent(arr + 1 , size - 1 , key);
    }
    

}

int main() {

    int arr[5] = {1,2,3,4,5};
    int size = 5;
    int key = 3;
    bool Present =  isPresent(arr,size,key);
    if(Present == true){
        cout<<"yes the key : "<<key<<" is present";

    }
    else{
        cout<<"key is not present";
    }
    

}