// approach 1

#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node*next;

    node(int data){
        this->data = data;
        this->next = nullptr;

    }

    ~node(){
        int value = this->data;
        if(this->next != nullptr){
            delete next;
            this->next = nullptr;
        }

    }
};


void insertAtHead(node* &head , node* &tail, int data){
    if(head == nullptr){
        node* temp = new node(data);
        head = temp;
        tail = temp;
    }else{
    node* temp = new node(data);
    temp->next = head;
    head = temp;
    }
}

void insertAtTail(node* &head , node* &tail, int data){
    if(tail == nullptr){
        node* temp = new node(data);
        head = temp;
        tail = temp;
    }else{
    node* temp = new node(data);
    tail -> next = temp;
    tail = temp;
    }
}

void insertAtMiddle(node* &head,node* &tail, int index, int data){
    if(index == 1){
        return insertAtHead(head,tail, data);
    }

    node* temp = head;
    int cnt = 1;

    while(cnt<index-1){
        temp = temp -> next;
        cnt++;
    }

    if(temp -> next == nullptr){
        return insertAtTail(head,tail,data);
    }

    node* nodetoinsert = new node(data);
    nodetoinsert -> next = temp -> next;
    temp -> next = nodetoinsert;

}

void print(node* &head){
    node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int palindrome(vector<int> arr){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    while(s<=e){
        if(arr[s] != arr[e]){
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}

int checkPalindrome(node* &head){
    node* temp = head;
    vector<int> arr;

    while(temp != nullptr){
        arr.push_back(temp -> data);
        temp = temp -> next;
    }

     return palindrome(arr);

}

int main(){
    node * head = nullptr;
    node* tail = nullptr;

    insertAtHead(head, tail , 1);
    print(head);
    insertAtHead(head, tail , 2);
    print(head);
    insertAtHead(head, tail , 1);
    print(head);

    bool ans = checkPalindrome(head);
    cout<<ans<<endl;
    if(ans){
        cout<<"true it is palindrome"<<endl;
    }else{
        cout<<"no it is not palindrome"<<endl;
    }


    //check palindrome

}    