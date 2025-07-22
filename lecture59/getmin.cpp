// design a stack that support getMin() in O(1) time complexity
#include<iostream>
#include<stack>
using namespace std;

class specialStack{

    stack<int> s;
    int mini;

    public:

    void push(int data){
        if(s.empty()){
            s.push(data);
            mini = data;
        }
        else{
            if(data < mini){
                int val = 2*data - mini;
                s.push(val);
                mini = data;
            }
            else{
                s.push(data);
            }
        }
    }

    int pop(){
        if(s.empty())
            return -1;

        int curr = s.top();
        s.pop();
        
        if(curr > mini){
            return curr;
        }
        else{
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top(){
        if(s.empty())
        return -1;

        int curr = s.top();
        if(curr < mini){
            return mini;
        }
        else{
            return curr;
        }

    }

    bool isEmpty(){
        return s.empty();
    }

    int getMin(){

        if(s.empty())
            return -1;

        return mini;    
    }

};

int main(){
specialStack s;
s.push(5);
s.push(3);
s.push(7);
s.push(2);
s.push(8);
cout << "Min: " << s.getMin() << endl;
cout << "Top: " << s.top() << endl; 
s.pop();
cout << "Min: " << s.getMin() << endl;
cout << "Top: " << s.top() << endl; 
s.pop();
cout << "Min: " << s.getMin() << endl;
cout << "Top: " << s.top() << endl; 

}