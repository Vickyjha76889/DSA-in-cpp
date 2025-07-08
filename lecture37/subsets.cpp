#include<iostream>
using namespace std;

void solve(vector<int> nums, vector<int> ouptput, int index, vector<vector<int>> &ans) {
     if(index>= num.size()){
        ans.push_back(output);
        return ;
     }
    
     solve(nums , output, index+1, ans);

     int element = num[index];
     output.push_back(element);
     solve(nums,output,index+1,ans);
}

vector<vector<int>> subset(vector<int> & nums){
    vector<vector<int>> ans;
    int index = 0;
    vector<int> output;
    solve(nums, output, index, ans);
    return ans;

}

}

int main(){
   vector<int> nums = {1,2,3};
   subset(nums); 
}