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

    void deletion(){
        if(size == 0){
            return ;
        }
        // step1:-
        arr[1] = arr[size];
        size--;  // Step 2:


        //step3:-
        int i = 1;
        while(i <= size){
            int leftindex = 2*i;
            int rightindex = 2*i + 1;
            if(leftindex <= size && arr[i] < arr[leftindex]){
                swap(arr[i] , arr[leftindex]);
                i = leftindex;
            }
            else if (rightindex <= size && arr[i] < arr[rightindex]){
                swap(arr[i] , arr[rightindex]);
                i = rightindex;
            }
            else{
                return;
            }
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
    h.deletion();
    h.print();
    return 0;
}