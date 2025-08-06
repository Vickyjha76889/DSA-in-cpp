#inlude<iostream>
using namespace std;
char MaxOccuringChar(string s){
    int arr[26] = {0};
    for(int i =  0; i<s.length();i++){
        char ch = s[i];
        int number = 0;
        number = ch -'a';
        arr[number]++;
    }
    int max = -1, ans = 0;
    for(int i = 0; i<26;i++){
        if(max<arr[i]){
            ans = i;
            max = arr[i];

        }
    }
    char finalAns  = 'a' + ans;
    return finalAns;
}
int main(){
    string s;
    cin>>s;
    char ans = MaxOccuringChar(s);
    cout<<ans<<endl;

}