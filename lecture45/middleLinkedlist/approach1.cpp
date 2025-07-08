#include<iostream>
using namespace std;

class node{
    
    public:
       int data;
       node* next;
       
       node(int data){
           this->data = data;
           this->next = nullptr;
       }
       ~node(){
           int value = this->data;
           if(next != nullptr){
               delete next;
               next = nullptr;
           }
       }
    };
    
    void insertAtHead(node* &head , node* &tail, int data){
        if(head == nullptr){
            node* temp = new node(data);
            head = temp;
            tail = temp;
        }
        else{
        node* temp = new node(data);
        temp->next = head;
        head = temp;
        }
        
    }
    
    void insertAtTail(node* &head,node* &tail, int data){
        if(tail == nullptr){
            node* temp = new node(data);
            head = temp;
            tail = temp;
        }
        else{
        node * temp = new node(data);
        tail -> next = temp;
        tail = temp;
        }
        
    }
    
   int sizeofLL(node* &head){
        
        node* temp = head;
        int cnt = 0;
        
        while(temp != nullptr){
            temp = temp->next;
            cnt++;
        }
        return cnt;
        
    }
    
    int middleElement(node* &head){
        
        int length = sizeofLL(head);
        int middle = length/2 + 1;
        return middle;
        
    }
    void middleNode(node* head, int cnt){
        node* temp = head;
        int count = 0;
        while(count != cnt){
            temp = temp -> next;
            count++;
        }
        cout<<temp->data;
    }
    
    void print(node* & head){
        node* temp =  head;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    
    int main(){
        
        node*head = nullptr;
        node*tail = nullptr;
        insertAtHead(head,tail,10);
        print(head);
        insertAtTail(head,tail,20);
        print(head);
        insertAtHead(head,tail,10);
        print(head);
        insertAtTail(head,tail,20);
        print(head);
        insertAtHead(head,tail,10);
        print(head);
        insertAtTail(head,tail,20);
        print(head);
        insertAtTail(head,tail,20);
        print(head);
        insertAtTail(head,tail,20);
        print(head);
        
        int center = middleElement(head);
        cout<<center<<endl;
        middleNode(head,center);
       
    }