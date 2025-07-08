#include<iostream>
using namespace std;
int main(){
    int i = 5;
    int &j = i; // j is a reference to i
    cout<<j<<endl;
    j = 10;  // both are same  but different name therfore i value is also modified
    cout<<i<<endl;;
}