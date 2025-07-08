// recuresion start

#include <iostream>
using namespace std;

int factorial(int n){
    if(n==0 or n==1){   // base case
        return 1;
    }
    return n * factorial(n-1);
}
int main(){
    int n;
    cout<< " Enter a Number: ";
    cin>>n;

    int fact = factorial(n);
    cout<< " Factorial of  "<< n << " is : " << fact << endl;
    return 0;


}