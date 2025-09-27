//heapify
// with maxheap and minheap
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

void heapifyMAXheap(int arr[] , int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i +1;

    if(left <=n && arr[largest] <arr[left]){
        largest = left;
    }
    if(right <=n && arr[largest] <arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        heapifyMAXheap(arr,n,largest);
    }
}

void heapifyMinHeap(int arr[] , int n , int i){
    int smallest = i;
    int left = 2*i ;
    int right = 2 * i  + 1;

    if(left <= n && arr[smallest] > arr[left]){
        smallest = left;
    }

    if(right <= n && arr[smallest] > arr[right]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr[smallest],arr[i]);
        heapifyMinHeap(arr,n,smallest);
    }

}

int main(){
    // heap h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.deletion();
    // h.print();

    int arr[6] = {-1,54,53,55,52,50};
    int n = 6;
    for(int i = n/2 ;i>=1;i--){
        heapifyMAXheap(arr,n-1,i);
    }

    cout<<endl;
    for(int i = 1;i<=n-1;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i = n/2 ;i>=1;i--){
        heapifyMinHeap(arr,n-1,i);
    }

    cout<<endl;
    for(int i = 1;i<=n-1;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}