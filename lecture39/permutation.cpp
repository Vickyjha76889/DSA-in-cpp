#include<iostream>
#include<vector>
using namespace std;

void solve(string s , int index , vector<string> &ans){

    if(index>=s.length()){  //base case
        ans.push_back(s);
        return;
    }

    for(int i = index ; i<s.length() ; i++){
        swap(s[i],s[index]);  
        solve(s , index+1  , ans);  // call himself as recursive function
        swap(s[i],s[index]);
    }

}

vector<string> permutation(string s){

    vector<string> ans ;
    int index = 0;
    solve(s , index, ans); // call funtion
    return ans;


}


int main(){
    string s ;

    cout<<"enter somethig ";

    cin>>s;

    vector<string> b = permutation(s); // call funtion

    for(string a : b){  //for printing
        cout<<a<<" ";
    }

     return 0;

}
