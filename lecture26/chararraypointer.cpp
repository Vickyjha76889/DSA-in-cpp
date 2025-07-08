#include<iostream>
using namespace std;
int main(){
    char ch[6] = "abcde";
    cout<<ch<<endl; // this will print the whole string;
    char *c =&ch[0];
    cout<<c;
}