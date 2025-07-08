class solution{
    private:
    bool valid(char ch){
        if((ch>='a' && ch<='z' )||(ch>='A' && ch<='Z' ) ||(ch>='0' && ch<='9' )){
            return 1;
        }
        else {
            return 0;
        }
    }

    char tovalidcase(char ch){
        if((ch >='a' && ch<="z" )||(ch>='a' && ch<='z' )){
            return temp;
        }
        else{
            char temp  = ch - "A" + "a";
            return temp;
        }
    }
   
}
bool checkpalindrome(string ch){  // Incorrect parameter type (should be string)
    int s = 0;
    int e = ch.length()-1;
    bool ispalindrome = true;
    while(s<=e){  // Should be while(s <= e)
        if(ch[s] != ch[e]){
            ispalindrome false; // Incorrect syntax
        }
        s++;
        e--;
    }
    return ispalindrome;
}


class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(int j= 0 ; j <s.length();j++){  // Variable mismatch (i vs j)
            if(valid (s[j])){  // Missing closing parenthesis
                temp.push_back(s[j];)  // Incorrect syntax
            }
        }
        for(int j = 0 ; j<s.length(); j++){  // Variable mismatch (i vs j)
            temp[j] = tovalidcase(temp[j]); // Incorrect function name
        }

        return check palindrome(temp); // Incorrect function name
    }
};
