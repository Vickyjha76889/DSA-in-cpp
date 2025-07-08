// #include<iostream>
// using namespace std;

// void print(int & i){
//     cout<<i<<endl;
//     cout<<&i<<endl;
    
// }
// int main(){
//     int i =5;
//     print(i);

// }


#include<iostream>
using namespace std;
int i = 5;
void print(){
    cout<<i<<endl; //accessing from global variable
}
int main(){
    int j = 10;
    cout<<j<<endl; //accesing from global variable
    cout<<i<<endl;
    print(); //calling function that accesses global variable

}