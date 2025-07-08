#include<iostream>
using namespace std;
int getlength(char ch[]){
    int count = 0;
    for(int i = 0;  ch[i]  != '\0'; i++){
        count++;
    }
    return count;    
  
}
void reverse(char ch[]){
    int s = 0; 
    int e = getlength(ch) - 1;
    while(s<e){
        swap(ch[s],ch[e]);
        s++;
        e--;
    }
  
}
bool palindrome(char ch[]){
    int s = 0;
    int e = getlength(ch) -1;
    bool ispalindrome = true;
    while(s<=e){
        if(ch[s] != ch[e]){
            ispalindrome  = false;
            break;
        }
        
        s++;
        e--;
    }
    return ispalindrome;
}

int main(){
    char ch[10];
    cout<<"enter your name:";
    cin>>ch;
    cout<<"your name is "<<ch<<endl;
    reverse(ch);
    cout<<"your name in reverse is "<<ch<<endl;
    cout<<getlength(ch)<<endl;
    cout<<"is your name palindrome?"<<palindrome(ch)<<endl;
}