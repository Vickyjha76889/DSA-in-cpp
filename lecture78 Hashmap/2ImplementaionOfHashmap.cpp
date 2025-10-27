// basic of hashmap implementation in c++
// in this we know about the implementation insertion ans deletion

#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
using namespace std;

int main(){
    unordered_map<string,int> m;
    // insetion 
    pair<string,int> p = make_pair("vicky",1);
    m.insert(p);
    
    // another method of insertion
    m["vicky"] = 3;
    // this will update the value of vicky to 3 from 1 instead of creating of making another 
    m["mrinal"] = 2;
    m["aman"] = 6;
    m["prem"] = 4;
    m["ani"] = 5;
    // searching
    cout<<m["vicky"]<<endl;
    //cout<<m.at("unknown")<<endl; // this will give error if key is not present

    cout<<m["unknown"]<<endl; // but this will not give error it will insert the key with value 0;
    cout<<m.at("unknown")<<endl;

    cout<<m.size()<<endl;

    

    cout<<m.count("mrinal")<<endl;// this will return 0 if key is not present else it will return 1;
    cout<<m.count("vicky")<<endl;

    cout<<m.count("unknown")<<endl;
    //deletion
    m.erase("unknown");
    cout<<m.count("unknown")<<endl;

    // iteration

    for(auto i:m){
        cout<<i.first<< " " <<i.second <<endl;
    }

}