// basic of hashmap implementation in c++
// in this we know about the implementation insertion ans deletion

#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
using namespace std;

int main(){
    unordered>map<string,int> map;
    // insetion 
    pair<string,int> p = make_pair("vicky",1);
    map.insert(p);
    
    // another method of insertion
    map["vicky"] = 3;
    // this will update the value of vicky to 3 from 1 instead of creating of making another 

    
}