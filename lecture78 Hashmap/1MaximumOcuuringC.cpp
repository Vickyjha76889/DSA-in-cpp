#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int maximumOccuringElement(string str) {
    int arr[26] = {0};
    for(int i = 0;i<str.length();i++){
        char ch = str[i];
        int number = 0;
        number = ch - 'a';
        arr[number]++;
    }

    int ans = 0;
    int maxi = -1;
    for(int i = 0;i<26;i++){
        if(maxi < arr[i]){
            maxi = arr[i];
            ans = i;
        }
    }

    return ans + 'a';
}

// int maximumOccuringElement(string str) {
//     int arr[26] = {0};
    
//     for(int i = 0;i<str.length();i++) {
//         char ch = str[i];
//         int number = 0;
//         number = ch- 'a';
//         arr[number]++;
//     }

//     int maxi = -1;
//     int ans = 0;
//     for(int i = 0;i<26;i++){
//         if(maxi < arr[i]){
//             ans = i;
//             maxi = arr[i];
//         }
//     }

//     return ans + 'a';
// }


int main(){
    string str = "appleapp";
    char ans = maximumOccuringElement(str);
    cout<<ans<<endl;
    return 0;
    
}