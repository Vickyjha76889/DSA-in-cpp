#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node*random;

    node(int data){
        this->data = data;
        this ->next = nullptr;
        this -> random = nullptr;
    }

};

void print(node* head){
        node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

}

void printrandom(node*head ){

    node* temp = head;
    while(temp != nullptr){
        if(temp->random != nullptr){
            cout<<temp->random->data<<" ";

        }
        else{
            cout<<"NULL ";
        }
        temp = temp ->next;
    }
    cout<<endl;

}

void insertAtTail(node* &head, node* &tail,int data){
    if(tail == nullptr){
        node* temp = new node(data);
        tail = temp;
        head = temp;
    }else{
        node* temp = new node(data);
        tail->next = temp;
        tail = temp;
    }
}

node* clonenode(node* &head){
    if(!head) return  nullptr;

    node* temp = head;
    node* clonehead = nullptr;
    node* clonetail = nullptr;

    // step1 clone the node

    while(temp != nullptr ){

        insertAtTail(clonehead,clonetail,temp->data);
        temp = temp->next;

    }

    // step 2 clone node add between original linkedlist

    node* next = nullptr;

    while(head != nullptr ){

        next = head->next;
        head->next = clonehead;
        head = next;

        next = clonehead->next;
        clonehead->next = head;
        clonehead = next;

    }

    // random pointer copy;

    temp = head;
    while(temp != nullptr){
        if(temp->next != nullptr && temp->random != nullptr){
            if(temp->random != nullptr){
                temp->next->random = temp->random ->next;
            }
        }
    }
    
    // node* originalnode = head;
    // node* clonenode = clonehead;
    // while(head != nullptr && clonehead != nullptr){
    //     originalnode->next = clonenode->next;
    //     originalnode = originalnode->next;

    //     if(originalnode != nullptr){

    //         clonenode->next = originalnode->next;
    //         clonenode = clonenode->next;

    //     }
    
node* original = head;
node* clone = head->next;
node* cloneHead = clone;

while(original != nullptr && clone != nullptr){
    original->next = clone->next;
    original = original->next;

    if(original != nullptr){
        clone->next = original->next;
    }
    clone = clone->next;
}
return cloneHead;

}




int main(){
    node* head = new node(1);
    node* second = new node(2);
    node* third = new node(3);
    node* fourth = new node(4);
    node* fifth = new node(5);

    head -> next = second;
    second -> next = third;
    third-> next = fourth;
    fourth -> next = fifth;

    head -> random = third;
    third -> random = fifth;
    fifth -> random = second;
    second -> random = head;
    fourth->random = third;
    print(head);
    printrandom(head);

    head = clonenode(head);
    print(head);
    printrandom(head);

}