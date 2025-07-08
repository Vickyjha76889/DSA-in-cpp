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
        if(this->next !=nullptr){
            delete next;
            this->next = nullptr;
        }
    }
};

void insertHead(node* &head,node* &tail, int data){
    if(head == nullptr){
       node* temp = new node(data);
       head = temp;
       tail = temp;
    }

    node* temp = new node(data);
    temp->next = head;
    head = temp; 
}

node* deleteDuplicate(node* head){
    if(head == nullptr){
        return nullptr;
    }

    node* curr = head;
    while(curr != nullptr){
        node* prev = curr;
        node* temp = curr->next;
        while(temp != nullptr){
            if(curr->data == temp->data){
                prev->next = temp->next;
                temp->next = nullptr;
                delete temp;
                temp = prev->next;
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    return head;
}

void print(node* &head){
    node* temp = head;
    while(temp!= nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    node *node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    insertHead(head,tail,20);
    print(head);
    insertHead(head,tail,10);
    insertHead(head,tail,20);
    print(head);
    head = deleteDuplicate(head);
    print(head);
}