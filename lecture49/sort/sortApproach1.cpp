// sort of 0s 1s 2s

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
};

void insertAtHead(node* &head, int data){

    node* temp =  new node(data);
    temp->next = head;
    head = temp;

}

void print(node* &head){

    node* temp = head;

    while(temp != nullptr){

        cout<<temp->data<<" ";
        temp = temp->next;


    }

    cout<<endl;

}

void insertatTail(node* &tail , node* curr){

    node* temp = curr;
    tail -> next = temp;
    tail = temp;

}

node* sortLL(node* head){

    node* zerohead = new node(-1);
    node* zerotail = zerohead;

    node* onehead = new node(-1);
    node* onetail = onehead;

    node* twohead = new node(-1);
    node* twotail = twohead;

    node* curr = head;

    while(curr != nullptr){

        int value = curr -> data;

        if(value == 0){
            insertatTail(zerotail,curr);
        }else if(value == 1){
            insertatTail(onetail,curr);
        }else if( value == 2){
            insertatTail(twotail,curr);
        }

        curr = curr -> next;

    }

    //merge

    if(onehead -> next != nullptr){

        zerotail ->next = onehead -> next;

    }
    else{

        zerotail -> next = twohead -> next;

    }

    onetail -> next = twohead -> next;
    twotail -> next = nullptr;

    node* newhead = zerohead->next;

    delete zerohead;
    delete onehead;
    delete twohead;

    return head;

}

int main(){

    node* node1 = new node(0);
    node* head = node1;

    print(head);

    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,0);

    cout<<"original list:";
    print(head);

    head = sortLL(head);

    cout<<"sorted list:";
    print(head);

    return 0;


}

