// //first method
// #include<iostream>
// using namespace std;

// void fibonacci(int n, int a = 0, int b = 1, int count = 0) {
//     if (count == n) return; // base case: stop after printing n terms

//     cout << a << " ";       // print current term

//     // move to next term
//     fibonacci(n, b, a + b, count + 1);
// }

// int main() {
//     int n;
//     cout << "Enter the number of terms in the Fibonacci series: ";
//     cin >> n;
//     fibonacci(n);
//     return 0;
// }

//second method
#include<iostream>
using namespace std;
int fibbonacci(int n, int a , int b, int count = 0){
    if(count == n){
        cout << " ";
    return  0;
  }
  count++;
  int c = a + b;
  cout << a <<" ";
  a = b; 
  b = c;
  return fibbonacci(n, a , b, count);

}
int main(){
    int n, a = 0, b = 1, c;
    cout << "enter the number of terms in the fibonacci series: ";
    cin>>n;
    fibbonacci(n , a , b);
    return 0 ;
}



// //third method
// #include<iostream>
// using namespace std;
// int fibo(int n){
//     if( n == 0 || n == 1){
//         return 1;
//     }
//     int ans = fibo(n-1) + fibo(n-2);
//     cout<<ans;
// }
// int main(){
//     int n;
//     cin>>n;
//     fibbo(n);
// }


// fourth method
// //using loop
// #include <iostream>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int a = 0 , b = 1,c ;
//        if(n >= 0){
//         cout<< a << " ";
//        }
//        if(n >= 1){
//         cout<< b << " ";
//        }

//        for(int i = 2; i< n ; i++){
//         c = a + b;
//         cout<< c << " ";
//         a = b;
//         b = c;
//        }
// }