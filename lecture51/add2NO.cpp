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
};

void inserttoHead(node* &head,node* &tail, int data){

    if(head == nullptr){
        node* temp = new node(data);
        head = temp;
        tail = head;
    }else{
    node* temp = new node(data);
    temp->next = head;
    head = temp;  
    }

}

void insertInTail(node* &head,node* &tail, int data){

     if(tail == nullptr){
        node* temp = new node(data);
        head = temp;
        tail = head;
    }else{

    node* temp = new node(data);
    tail->next = temp;
    tail = temp;
    }

}

node* add(node* l1, node* l2){
    int carry = 0;
    node* anshead = nullptr;
    node* anstail = nullptr;

    while(l1 != nullptr && l2 != nullptr){
        int sum = carry + l1->data + l2->data;
        int digit = sum%10;

        insertInTail(anshead, anstail,digit);
        carry = sum/10;
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1!= nullptr){
        int sum = carry + l1->data;
        int digit = sum % 10;
        insertInTail(anshead, anstail , digit);
        carry = sum/10;
        l1 = l1->next;
    }
    while(l2!= nullptr){
        int sum = carry + l2->data;
        int digit = sum % 10;
        insertInTail(anshead, anstail , digit);
        carry = sum/10;
        l2 = l2->next;
    }
    if (carry!=0){
        insertInTail(anshead, anstail,carry);
    }

    return anshead;

}

node* reverse(node* &head){
    node* curr = head;
    node* prev = nullptr;
    node* next = nullptr;
    while(curr!= nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
node* addtwosum(node* l1, node* l2){
   l1 = reverse(l1);
   l2 = reverse(l2);

   node* ans = add(l1,l2);
   ans = reverse(ans);
   return ans;
}

void print(node* & head){

    node* temp = head;
    while(temp!= nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

}

int main(){
    node * l1 = new node(9);
    node* head1 = l1;
    node* tail1 = l1;
    inserttoHead(head1, tail1,9);
    inserttoHead(head1,tail1,9);

    node* l2 = new node(9);
    node* head2 = l2;
    node* tail2 = l2;
    inserttoHead(head2, tail2,1);
    inserttoHead(head2,tail2,2);

    print(head1);
    print(head2);

    node* head = addtwosum(head1,head2);
    print(head);

}


