#include<iostream>
#include<queue>
#include<string>
#include<unordered_map>
using namespace std;

string FirstNonRepeating(string A){
    unordered_map<char , int > count;
    queue<char> q;
    string result;

    for(int i = 0 ; i < A.length() ; i++ ){
        char ch = A[i];
        count[ch]++;
        q.push(ch);

        while(!q.empty() ){

            if(count[q.front()] > 1){
                q.pop();
            }else{
                result += q.front();
                break;
            }
            
        }
        if(q.empty()){
            result += '#';
        }

        
    }

    return result;
}

int main(){
    string A = "aabcd";
    cout << FirstNonRepeating(A) << endl; // Output: "a#bb"
    return 0;
}