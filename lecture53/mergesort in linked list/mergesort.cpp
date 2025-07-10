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

void inertAtHead(node* &head, node* &tail, int data){

    if(head == nullptr){
        node* temp = new node(data);
        head = temp;
        tail = temp;
    }else{
        node* temp = new node(data);
        temp ->next  = head;
        head = temp;
    }

}

void insertAtTail(node* &head, node* &tail, int data){

    if(head == nullptr){
        node* temp = new node(data);
        head = temp;
        tail = temp;
    }else{
        node* temp = new node(data);
        tail -> next =  temp;
        tail = temp;
    }
}    

void print(node* head){

    node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp ->next;
    }
    cout<<endl;
}

//find mid function
node* findmid(node* &head){
    node* slow = head;
    node* fast = head -> next;
    while(fast != nullptr && fast -> next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// merge function
node* merge(node* left, node* right){

    if(left == nullptr){
        return right;
    }

    if(right == nullptr){
        return left;
    }

    node* ans = new node(-1);
    node* temp = ans;

    while(left != nullptr && right != nullptr){

        if(left->data < right->data){
            temp -> next = left;
            temp = left;
            left = left->next;
        }else{
            temp -> next = right;
            temp = right;
            right = right->next;
        }

    }

    while(left != nullptr){

         temp -> next = left;
            temp = left;
            left = left->next;

    }

    while(right != nullptr){

        temp -> next = right;
            temp = right;
            right = right->next;

    }

    ans = ans->next;
    return ans;

}

node* mergesort(node* head){

    //base case of recusrion
    if(head ==  nullptr || head->next == nullptr){
        return head;
    }
    
    // break linked list into two parts
    node* mid = findmid(head);
    node* left = head;
    node* right = mid->next;
    mid->next =  nullptr;

    left = mergesort(left);
    right = mergesort(right);

    // merge  two divided linked 
    node* result =  merge(left,right);

    return result;

}

int main(){

    node* node1 = new node(2);
    node*head = node1;
    node*tail = node1;

  insertAtTail(head,tail,5);
  insertAtTail(head,tail,1);
  insertAtTail(head,tail,3);
  insertAtTail(head,tail,6);
  print(head);

  head = mergesort(head);
  print(head);

}
    

