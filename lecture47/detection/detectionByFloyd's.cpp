#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to detect loop using Floyd’s Cycle Detection
bool detectLoop(Node* head) {
    if (head == nullptr) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;           // move by 1 step
        fast = fast->next->next;     // move by 2 steps

        if (slow == fast) {
            return true;  // Loop detected
        }
    }

    return false; // No loop
}

// Helper function to insert node at tail
void insertTail(Node* &tail, int data) {
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

int main() {
    Node* head = new Node(1);
    Node* tail = head;

    insertTail(tail, 2);
    insertTail(tail, 3);
    insertTail(tail, 4);
    insertTail(tail, 5);

    // Creating a loop for testing
    tail->next = head->next; // 5 -> 2

    if (detectLoop(head)) {
        cout << "Loop is present" << endl;
    } else {
        cout << "No loop found" << endl;
    }

    return 0;
}




// #include <iostream>
// using namespace std;

// class node{
  
//    public:
//       int data;
//       node*next;
      
      
//       node(int data){
//         this->data= data;
//         this->next = NULL;
//       }
// };

// bool detectLoop(node* &head){
//   node *slow = head;
//   node* fast = head;
//   while(slow!= NULL && fast!= NULL && fast->next!= NULL){
//     slow = slow->next;
//     fast = fast->next->next;
    
      
//     if(slow == fast){
//       return true;
//     }  
    
//   }
//   return false;
// }

// void insertTail(node* &tail, int data){
//    if(tail == NULL){
//      node* temp = new node(data);
//      tail = temp;
//      tail->next = NULL;
//    }
//    node* temp = new node(data);
//    tail->next  = temp;
//    tail = temp;
   
   
   
// }

// void print(node* &head){
//   node* temp = head;
//   while(temp != NULL){
//     cout<<temp->data<<" ";
//     temp = temp->next;
//   }
//   cout<<endl;
// }

// int main(){
//   node *node1 = new node(10);
//   node* tail = node1;
//   node* head = node1;
//   insertTail(tail,20);
//   insertTail(tail,30);
//    insertTail(tail,40);
//    print(head);
//   insertTail(tail,50);
//   print(head);
//   if(detectLoop(head)){
//     cout<< "loop is found"<<endl;
//   }
//   else{
//     cout<<"loop  not fount"<<endl;
//   }
  
// }







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


// // bool detectLoop(Node* &head){
// //     if(head == nullptr){
// //         return false;
// //     }
// //     Node* temp = head;
// //     map<Node* , bool> visited;

// //     while (temp!= nullptr){
// //         if(visited[temp]==true){
// //             return true;
// //         }
// //         visited[temp] = true;
// //         temp = temp->next;

// //     }
// //     return false;
    
// // }

// node* detectLoopByFloyds(Node* &head){

//     if(head == nullptr){
//         return nullptr;
//     }

//     Node* slow = head;
//     Node* fast = head;
//     while(fast != nullptr && fast->next != nullptr && slow != nullptr){
//         slow = slow->next;
//         fast = fast->next->next;
//         if(fast == slow){
//             return true; // loop detected
//         }
//     }
//     return false; // no loop detected

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
//     tail->next = head->next;

//     insertHead(head, 10);
//     insertHead(head, 20);
//     insertHead(head, 30);
//     insertHead(head, 40);
//     print(head);
//     insertTail(tail, 20);
//     insertTail(tail, 30);
//     insertTail(tail, 40);
//     print(head);
//     // bool a =  detectLoop(head);
//     cout<<"Loop detected: ";
//     if(detectLoopByFloyds(head) != false){
//         cout<<"yes"<<endl;
//     }else{
//         cout<<"no"<<endl;
//     }
    
// }