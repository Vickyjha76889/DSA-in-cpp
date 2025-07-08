#include<iostream>
#define PI 3.14 // this is macros
#define square(x) ((x)*(x)) // these shotcuts that we define earlier is macros
using namespace std;
int main(){
    cout<<"value of pi is :"<<PI<<endl;
    cout<<"area of rectangle is :"<<PI * square(5)<<endl;
}