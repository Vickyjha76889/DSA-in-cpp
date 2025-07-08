#include<iostream>
using namespace std;
 inline int  getSum(int &a , int &b){  //this function will send a copy therefore takes less space time
    return a + b;
}

int main(){
    int a = 5,  b = 10;
    int ans = 0;
    ans = getSum( a , b); //here
    cout<<"sum of these two number is :"<<ans<<endl;
    a = a +3;
    b = b+2;
    ans = getSum( a , b);  //here
    cout<<ans;
    return 0;
}