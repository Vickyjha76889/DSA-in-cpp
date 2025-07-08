#include<iostream>
using namespace std;
int gcd(int a, int b){
    if(a == 0){
        return b;
    }
    if(b == 0){
        return a;
    }
    if(a == b){
        return a;
    }
    while (a != b){
        if(a > b){
            a = a-b;
        }
        else{
            b = b-a;
        }

    }
    return a;

}

int main(){
    int a, b;
    cout<<"enter two numbers:";
    cin>>a>>b;
    int ans = gcd(a,b);
    cout<<"HCF of "<<a<<" and "<<b<<" is: "<<ans<<endl;
    cout<<"hello world"<<endl;
}