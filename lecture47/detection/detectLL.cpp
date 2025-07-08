// //detect likend list loop

// #include<iostream>
// #include<map>
// using namespace std;

// class Node{
//     public:
//        int data;
//        Node*next;


//        Node(int data){
//         this->data = data;
//         this->next = nullptr;
//        }

    
       
// };

// void insertHead(Node* &head, int data){
//     Node* temp = new Node(data);
//     temp->next = head;
//     head = temp;
// }

// void insertTail(Node* &tail, int data){
  
//     // if(tail == nullptr){
//     //     Node* temp = new Node(data);
//     //     tail = temp;
//     // }

//     Node* temp = new Node(data);
//     tail->next = temp;
//     tail = temp;
// }


// bool detectLoop(Node* &head){
//     if(head == nullptr){
//         return false;
//     }
//     Node* temp = head;
//     map<Node* , bool> visited;

//     while (temp!= nullptr){
//         if(visited[temp]==true){
//             return true;
//         }
//         visited[temp] = true;
//         temp = temp->next;

//     }
//     return false;
    
// }

// void print(Node* &head){
//     Node* temp = head;
//     while(temp != nullptr){
//         cout<<temp->data<<" ";
//         temp = temp->next;
//     }
//     cout<<endl;
// }

// int main(){

//     Node * node1 = new Node(10);
//     Node* head = node1;
//     Node* tail = node1;

//     insertHead(head, 10);
//     insertHead(head, 20);
//     insertHead(head, 30);
//     insertHead(head, 40);
//     insertTail(tail, 20);
//     insertTail(tail, 30);
//     insertTail(tail, 40);
//     print(head);
//     bool a =  detectLoop(head);
//     cout<<"Loop detected: ";
//     if(a){
//         cout<<"yes"<<endl;
//     }else{
//         cout<<"no"<<endl;
//     }
    
// }








#include<iostream>
#include<map>
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
bool detectLoop(node* tail){
    if(tail == nullptr){
        return false;
    }
    node* temp = tail;
    map<node* , bool> visited;

    while (temp!= nullptr){
        if(visited[temp]==true){
            return true;
        }
        visited[temp] = true;
        temp = temp->next;

    }
    return false;
    
}
bool isCircular(node* &tail){

    if(tail == NULL){
        return true;
    }

    node* temp = tail;
    while(temp != nullptr && temp != tail){
        temp = temp->next;
    }
    if(temp == tail){
        return true;
    }
    else{ 
        return false;
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
    // deleteNode(tail,10);
    // print(tail);
    insert(tail,20,30);
    print(tail);
    insert(tail,30,40);
    print(tail);
    bool ans = isCircular(tail);
    if(ans){
        cout<<"The linked list is circular"<<endl;
    }
    else{
        cout<<"The linked list is not circular"<<endl;
    }
    bool a =  detectLoop(tail);
    cout<<"Loop detected: ";
    if(a){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
}