#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;
    node*prev;

    node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev =   nullptr;
    }
};

//insert at head of doubly linked list
void insertAtHead(node* &head, int data){   
    node* temp = new node(data);
    temp -> next = head;
    head-> prev = temp;
    head = temp;
}

//insert at tail of doubly linked list
void insertAtTail(node* &tail, int data){
node* temp = new node(data);
//    if (tail != nullptr) {
//        tail->next = temp;
//        temp->prev = tail;
//    } else {
//        // If list was empty, head should also point to the new node
//        head = temp;
//    }
    tail->next = temp;
    temp->prev = tail;

   tail = temp;
}

void insertAtMiddle(node* &head, node* &tail, int pos, int data){
    if(pos == 1){
        insertAtHead(head,data);
        return;
    }

    node* temp = head;
    int cnt = 1;
    while(cnt<pos-1){
        temp= temp->next;
        cnt++;

    }
    if(temp->next == nullptr){
        insertAtTail(tail,data);
        return;
    }

    node* nodetoinsert = new node(data);
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
}


void print(node* &head){
    node* temp = head;
    while(temp!= nullptr){
        cout<<temp->data<<" " ;
        temp = temp-> next;
   }
   cout<<endl;
}

int main(){
    node *node1 =  new node(10);
    node *head = node1;
    node *tail = node1;
    insertAtHead(head,20);
    print(head);
    insertAtHead(head,30);
    print(head);
    insertAtHead(head,40);
    print(head);

    insertAtTail(tail,20);
    print(head);
    insertAtTail(tail,30);
    print(head);

    insertAtMiddle(head,tail, 2,5);
    print(head);
 }