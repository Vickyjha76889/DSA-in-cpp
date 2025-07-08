#include<iostream>
using namespace std;
int main(){
    int arr[10] = {1,5,3,4,5,6,7,8,9,10};
    cout<<arr<<endl;;
    cout<<*(arr+1)<<endl;;
    cout<<2[arr]<<endl; // this is valid syntax in c++; 
    cout<<*(2+arr)<<endl; // this is also valid syntax in c++;
    
  int *ptr = &arr[0];
  cout<<ptr<<endl; // its store the value of another element;
  cout<<*ptr<<endl;
  cout<<&ptr; // the eddress of this pointer is different  because it is a different variable;
}  