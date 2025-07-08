#include<iostream>
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

void insert(node* & tail, int element, int data){
    
    if(tail == nullptr){
        node* newnode = new node(data);
        tail = newnode;
        newnode->next = newnode;
    }
    else{
        node* curr = tail;
         while(curr->data != element){
            curr = curr->next;
         }
         node* temp = new node(data);
         temp->next = curr->next;
         curr->next = temp;
        
    }
}

void deleteNode(node* &tail, int value){
    if(tail == nullptr){
        cout<<"list is already empty"<<endl;
        return;
    }
    else{
        node* prev = tail;
        node* curr = prev->next;
        while(curr-> data != value){
            prev = curr;
            curr = curr->next;
        }
        if(curr == tail){
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = nullptr;
        delete curr;
    }
}

void print(node* &tail){
    node* temp = tail;
    if(tail == nullptr){
        cout<<"list is empty"<<endl;
        return;
    }
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != tail);
    cout<<endl;
}
int main(){
    node * tail = nullptr;
    insert(tail,1,10);
    print(tail);
    insert(tail,10,20);
    print(tail);
    deleteNode(tail,10);
    print(tail);
    insert(tail,20,30);
    print(tail);
}