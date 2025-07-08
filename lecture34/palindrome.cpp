#include<iostream>
using namespace std;

bool isPalindrome(string palindrome , int s , int end) {

    if(s >= end){
        return true;
    }
     if(palindrome[s] != palindrome[end]){
        return false;
     }
     return isPalindrome(palindrome,s+1, end-1);


}

int main() {

    string palindrome = "nitin";
    int s = 0 ;
    int end = palindrome.length()-1;
    bool ans  = isPalindrome(palindrome,s,end);
    if(ans == true){
        cout<<"palindrome is valid";
    }
    else{
        cout<<"palindrome is not valid";
    }


}