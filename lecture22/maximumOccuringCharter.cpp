// #include <iostream>  // Standard library for input and output operations
// #include <string>     // Library for handling string operations
// using namespace std;

// char MaxOccuringChar(string s) {
//     int arr[26] = {0};  // Array to store frequency of each lowercase character (a-z)
    
//     // Loop through each character of the string
//     for(int i = 0; i < s.length(); i++) {
//         char ch = tolower(s[i]); // Convert character to lowercase for uniform counting
        
//         // Ensure only letters are counted (ignoring numbers/special characters)
//         if(ch >= 'a' && ch <= 'z') {
//             int number = ch - 'a'; // Mapping 'a' to index 0, 'b' to 1, etc.
//             arr[number]++; // Increment occurrence count of the character
//         }
//     }
    
//     int max = -1, ans = 0; // Variables to track the most occurring character
    
//     // Loop through frequency array to determine the highest occurring character
//     for(int i = 0; i < 26; i++) {
//         if(max < arr[i]) { // If a new max frequency is found
//             ans = i;  // Store the index of the character
//             max = arr[i];  // Update max frequency
//         }
//     }
    
//     char finalAns = 'a' + ans; // Convert index back to character
//     return finalAns; // Return the most frequent character
// }

// int main() {
//     string s;
//     cin >> s; // Take input string from user

//     char ans = MaxOccuringChar(s); // Call function to determine most occurring character
//     cout << ans << endl; // Print the result
// }





#include<iostream>
#include<string>
using namespace std;

char MaxOccuringChar(string s) {
    int arr[26] = {0};

    for(int i =0;i<s.length(); i++){
        char ch = tolower(s[i]);
        int number = 0;
        number = ch - 'a';
        arr[number]++;

    }

    int max = -1, ans = 0;
    for(int i = 0; i<26;i++){
        if( max < arr[i]){
            ans = i;
            max = arr[i];
        }
    }

    char finalAns = 'a' + ans;
    return finalAns;
}

int main(){
    string s;
    cin>>s;
    char ans = MaxOccuringChar(s);
    cout<<ans<<endl;

}
