#include<iostream>
using namespace std;
int reachhome(int start, int end){
    if(start == end){
        cout << "reached home" <<endl;
        return 0;
    }

    cout<< "start = " << start << " end = " <<end<<endl;
    
    return reachhome(start + 1 , end);


}
int main(){
    int start, end;
    cout<< " enter start and end point" << endl;
    cin>> start ;
    cin>> end;
    reachhome(start , end);
}