// #include<iostream>
// using namespace std;
// int main(){
//     int arr[3][3] ={{1,2,3},{4,5,6},{7,8,9}};
//     int sr = 0;  // start row
//     int er = 2;  // end row
//     int sc = 0;  // start column
//     int ec = 2;  // end column
//     int total = 3*3;
//     int count = 0;
//     while(count < total){
//         // print top row
//         for(int i = sc; i <= ec && count < total; i++){
//             cout << arr[sr][i] << " ";
//             count++;
//         }
//         sr++;
//         // print right column
//         for(int i = sr; i <= er && count < total; i++){
//             cout << arr[i][ec] << " ";
//             count++;
//         }
//         ec--;
//         // print bottom row
//         for(int i = ec; i >= sc && count < total; i--){
//             cout << arr[er][i] << " ";
//             count++;
//         }
//         er--;
//         // print left column
//         for(int i = er; i >= sr && count < total; i--){
//             cout << arr[i][sc] << " ";
//             count++;
//         }
//         sc++;
//     }
//     return 0;
// }





#include <iostream>
using namespace std;

int main() {
   int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
   int sr = 0;
   int er = 2;
   int sc = 0;
   int ec = 2;
   int count = 0 ;
   int total = 3*3;
   while(count<total){
       for(int i = sc; i<=ec && count <total ; i++){
           cout<<arr[sr][i]<<" ";
           count++;
       }
       sr++;

       for(int i = sr; i<=er && count<total ; i++){
           cout<<arr[i][ec]<<" ";
          count++;
       }
       ec--;
       cout<<endl;

       for(int i = ec; i>=sc && count<total ; i-- ){
           cout<<arr[er][i]<<" ";
           count++;
       }
       er--;

         for(int i = er; i>=sr && count<total ; i-- ){
           cout<<arr[i][sc]<<" ";
           count++;
       }
       sc++;
       
       
   }

    return 0;
}