#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size = 0;

    void insert(int val){
        size++;
        int index = size;
        arr[index] = val;
        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent] , arr[index]);
                index = parent;
            }else{
                return;
            }
        }
    }

    void print(){
        for(int i = 0 ;i< size;i++){
            cout<<arr[i+1]<<" ";
        }
    }
};

int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    return 0;
}