#include<iostream>
#include<string>
using namespace std;

string  removeAdjecentDupilcate(string s){
    string result = "";
   for(char c : s){
    if(!result.empty() && result.back() ==c){
        result.pop_back();
    }
    else{
        result.push_back(c);
    }
   }
   return result;

}

int main(){
    string s ;
    cin>>s;
    string a = removeAdjecentDupilcate(s);
    cout<<a<<endl;
    return 0;
}