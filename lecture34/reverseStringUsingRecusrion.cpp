#include<iostream>
using namespace std;

string  reverseString(string&vicky, int start , int end) {
    if(start >= end) {
        return vicky;
    }
    swap(vicky[start],vicky[end]);
    return reverseString(vicky,start +1, end -1);

}

int main() {
    string  vicky = {"abcde"};
    int s = 0;
    int end = vicky.size()-1;
     string v =  reverseString(vicky,  s ,end);
    cout<<v<<endl;
    cout<<vicky;
    return 0;
}