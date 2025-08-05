// circular tour
/*   question no five (5);
 there is a circle with n number of petrol pump andthe given is petrol and distance to the next petrol
pump we have to find the starting point where we can start and can complete one loop of circle 
*/
 
#include<iostream>
using namespace std;

struct petrolpump{
    int petrol;
    int distance;
};

int tour(petrolpump p[] , int n){
    int deficient = 0;
    int balance = 0;
    int start = 0;
    for(int i = 0 ; i < n ; i++){
        balance += p[i].petrol - p[i].distance;
        if(balance < 0){
            deficient += balance;
            start = i + 1;
            balance = 0;
        }

    }
    if(deficient + balance >=0 ){
        return start;
    }
    else{
        return -1;
    }

}

int main() {
    int n = 6;
    // cout << "Enter number of petrol pumps: ";
    // cin >> n;

    petrolpump* p = new petrolpump[n];

    // cout << "Enter petrol and distance for each petrol pump:\n";
    // for (int i = 0; i < n; i++) {
    //     cin >> p[i].petrol >> p[i].distance;
    // }
    p[0].petrol = 6;
    p[1].petrol = 7;
    p[2].petrol = 4;
    p[3].petrol = 10;
    p[4].petrol = 6;
    p[5].petrol = 5;

    p[0].distance = 5; 
    p[1].distance = 6;
    p[2].distance = 7;
    p[3].distance = 8;
    p[4].distance = 6;
    p[5].distance = 4;

    int startPoint = tour(p, n);

    if (startPoint != -1) {
        cout << "Start at petrol pump: " << startPoint << endl;
    } else {
        cout << "No possible tour\n";
    }

    delete[] p;
    return 0;
}