#include<iostream>
using namespace std;
class student{
    private:
        int roll = 101;
        string name;
    public:
        void getroll(){
            this->roll = roll;
            cout<<roll;
        }    
};
int main(){
    student s1;
    // s1.getroll();
    cout << "\nRoll number: " ; // This will cause
    s1.getroll();
}