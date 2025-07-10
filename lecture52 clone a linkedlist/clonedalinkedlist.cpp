#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* random;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->random = nullptr;
    }
};
// Helper: Print the list with random pointers
void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << "Node: " << curr->data;
        if (curr->random != nullptr)
            cout << ", Random: " << curr->random->data;
        else
            cout << ", Random: NULL";
        cout << endl;
        curr = curr->next;
    }
}

// Example usage
int main() {
    // Creating the linked list manually
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;

    // Assigning random pointers
    head->random = third;    // 1 -> 3
    second->random = head;   // 2 -> 1
    third->random = nullptr; // 3 -> NULL
    fourth->random = second; // 4 -> 2

    cout << "Original List:\n";
    printList(head);

    // Node* clonedHead = cloneLinkedList(head);

    // cout << "\nCloned List:\n";
    // printList(clonedHead);

    // return 0;
}
