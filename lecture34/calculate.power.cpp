#include<iostream>
using namespace std;

int calPower(int a , int b){


    if(b == 0 )
        return 1;
    
    if(b == 1){
        return a;
    }    

    return a * calPower(a,b-1);
}

int main(){

    int a = 2;
    int b = 4;
    int c = calPower(a,b);
    cout<<c;

}