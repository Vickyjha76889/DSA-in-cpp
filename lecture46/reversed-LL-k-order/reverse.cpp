#include<iostream>
using namespace std;

class Node{
    public :
    int data;
    Node* next;
    
    Node(int data){
        this->data= data;
        this->next = nullptr;
    }
};

void InsertAtHead(Node* &head, Node* &tail , int data){
    if(head == nullptr){
        head = new Node(data);
        tail = head;
    }
    else{
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
        
    }
}

 void InsertAtTail(Node* & head, Node* &tail, int data){
     if(head == nullptr){
        head = new Node(data);
        tail = head;
    }
    else{
        Node* temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }
    
}

Node* kReversed(Node* & head, int key){
    if(head == nullptr){
        return nullptr;
    }
    Node* next = nullptr;
    Node* curr = head;
    Node* prev = nullptr;
    int cnt  = 0;
    while(curr != nullptr and  cnt < key){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }
    
    if(next != nullptr){
        head->next = kReversed(next, key);
    }
    
    return prev;
}


void print(Node* & head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp ->next;
    }
    cout<<endl;
}

int main(){
    Node*head = nullptr;
    Node*tail = nullptr;
    InsertAtTail(head,tail,10);
    print(head);
    InsertAtTail(head,tail,20);
    print(head);
     InsertAtTail(head,tail,30);
    print(head);
    InsertAtTail(head,tail,40);
    print(head);
      InsertAtTail(head,tail,50);
    print(head);
    InsertAtTail(head,tail,60);
    print(head);
     InsertAtTail(head,tail,70);
    print(head);
    InsertAtTail(head,tail,80);
    print(head);
    head = kReversed(head,2);
    print(head);
    
    
    
}