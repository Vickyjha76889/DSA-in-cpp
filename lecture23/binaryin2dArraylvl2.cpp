#include<iostream>
using namespace std;
int main(){
    int arr[4][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};
    int row = 4;
    int col = 5;

    int rowindex = 0;
    int colindex = col-1;
    int target = 15;
    while(rowindex<row && colindex>=0){
   int element =arr[rowindex][colindex];
     if(element == target){
        cout<<"element fount at index:" <<rowindex<<" "<<colindex<<endl;
        break;
     }
      if (element<target){
        rowindex++;
      }
      else{
        colindex--;
      }
    }
    return 0;
    arr[rowindex][colindex] = target;
}