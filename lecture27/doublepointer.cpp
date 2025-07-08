#include<iostream>
using namespace std;
void update(int **p){
    // p = p+1;
    
    *p = (*p) + 10; // this line change the adress of p

    **p = **(p) + 10; // this line will update the value of i but if the upper code run then the adress is changes so this will not work 

}
int main(){
    int i =5;
    int *p = &i;
    int **p2 = &p;

    cout<<"value of i :"<<i<<endl;
    cout<<"value of p :"<<p<<endl;
    cout<<"value of p2:"<<p2<<endl;
    cout<<endl;

    // cout<<"adress of i = :"<<&i<<endl;
    // cout<<" adress of p = :"<<&p<<endl;
    // cout<<"adress of p2 = : "<<&p2<<endl<<endl;

    // cout<<"value of i by pointer p : "<<*p<<endl;
    // cout<<"value of i by pointer p2 : "<< **p2<<endl<<endl;

    // cout<<"value of p by pointer p2 :"<<*p2<<endl<<endl;

    update(p2);
 
    cout<<"value of i  after update :"<<i<<endl;
    cout<<"value of p  after update :"<<p<<endl;
    cout<<"value of p2 after update :"<<p2<<endl;
    cout<<endl;

}