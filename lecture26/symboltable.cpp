#include<iostream>
using namespace std;
int main(){
    int arr[10];
    cout<<arr<<endl;;
    // arr = arr + 1; // this is not valid ; if you are not able to under stand then study symbol table concept;
    int  *ptr = arr;
    ptr = ptr + 1; // but this is valid;
    cout<<ptr<<endl;
    cout<<&arr[0];
}