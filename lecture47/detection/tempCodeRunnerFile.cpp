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

void print (Node* head){
  Node* temp = head;
  while(temp!= NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}

int main() {
    Node* head = new Node(1);
    Node* tail = head;

    insertTail(tail, 2);
    insertTail(tail, 3);
    insertTail(tail, 4);
    insertTail(tail, 5);
    print(head);

    // Creating a loop for testing
    tail->next = head->next; // 5 -> 2

    if (detectLoop(head)) {
        cout << "Loop is present" << endl;
    } else {
        cout << "No loop found" << endl;
    }

    return 0;
}
