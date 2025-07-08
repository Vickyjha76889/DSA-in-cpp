//approach1 by iterarive method

#include<iostream> //creating a linked list
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        this -> next = nullptr;
    }
    ~node(){
        int value = this-> data;
        if(this->next != nullptr){
            delete next;
            this->next = nullptr;
        }
    }
};

void InsertAtHead(node* &head, int data){
    node*n = new node(data);
    n->next = head;
    head = n;
}

void InsertAtTail(node* &tail, int data){
    node* temp = new node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(node* &tail, node * &head, int position  , int data){
    if(position == 1){
        InsertAtHead(head,data);
        return;
    }

    node* temp = head;
    int cnt = 1;

    while(cnt<position-1){
        temp = temp -> next;
        cnt++;
    }

    //insetion at last postion
    if(temp->next == nullptr){
        InsertAtTail(tail,data);
        return;
    }

    node* nodeToInsert = new node(data);
    nodeToInsert->next = temp->next;    
    temp->next = nodeToInsert;
}


void deleteNode(int pos, node* & head){

    if(pos == 1){
        node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }
    else{
        node *curr = head;
        node *prev = nullptr;
        int cnt = 1;
        while(cnt<pos){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = nullptr;
        delete curr;
    }

    
}
node* reversed(node* &head){
    node* prev = nullptr;
    node* curr = head;
    node* forward = nullptr;
    while(curr != nullptr){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

void print(node* head){
    node* temp  = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp ->next;  
      }
      cout<<endl;
}

int main(){
    node* node1 = new node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    node *head = node1;
    node *tail = node1;

    // InsertAtHead(head, 20);
    // print(head);
    // InsertAtHead(head, 30);
    // print(head);
    // InsertAtTail(tail, 40);
    // print(head);

    InsertAtTail(tail,20);
    print(head);
    InsertAtTail(tail,30);
    print(head);
    InsertAtTail(tail,40);
    print(head);

    insertAtPosition(tail, head , 4, 25 );
    print(head);
    head = reversed(head);
    print(head);

    // deleteNode(3, head);
    // print(head);

    return 0;
}