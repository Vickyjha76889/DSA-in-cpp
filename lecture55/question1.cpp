// reverese a string using stack

#include<iostream>
#include<stack>
using namespace std;

int main(){

    string str = "vickyjha";
    stack<char> s;
    string ans = " " ;

    for(char ch : str){
        s.push(ch);
    }

    while(!s.empty()){
        ans += s.top();
        s.pop();
    }

    cout<<"answer = :"<<ans;
}