#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    ~node() {
        if (this->next != nullptr) {
            delete next;
            this->next = nullptr;
        }
    }
};

void insertAtHead(node* &head, node* &tail, int data) {
    node* temp = new node(data);
    if (head == nullptr) {
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(node* &head, node* &tail, int data) {
    node* temp = new node(data);
    if (tail == nullptr) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void print(node* head) {
    node* temp = head;
    int count = 0; // safety to avoid infinite loop
    while (temp != nullptr && count < 100) {
        cout << temp->data << " ";
        temp = temp->next;
        count++;
    }
    cout << endl;
}

node* getmiddle(node* head) {
    node* slow = head;
    node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

node* reverse(node* head) {
    node* curr = head;
    node* prev = nullptr;
    node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

bool checkpalindrome(node* &head) {
    // Edge case: empty list or single node is always palindrome
    if (head == nullptr || head->next == nullptr) {
        return true;
    }

    // Step 1: Get middle
    node* mid = getmiddle(head);

    // Step 2: Reverse second half
    mid->next = reverse(mid->next);

    // Step 3: Compare both halves
    node* head1 = head;
    node* head2 = mid->next;

    while (head2 != nullptr) {
        if (head1->data != head2->data) {
            // Step 4: Restore the list before returning
            mid->next = reverse(mid->next);
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // Step 4: Restore the list (important to keep original list intact)
    mid->next = reverse(mid->next);

    return true;
}

int main() {
    node* head = nullptr;
    node* tail = nullptr;

    // Creating a list: 1 -> 2 -> 1
    insertAtHead(head, tail, 1);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);

    cout << "Linked list: ";
    print(head);

    bool ans = checkpalindrome(head);

    cout << "Is Palindrome? " << (ans ? "Yes" : "No") << endl;

    // Optional: print again to confirm list is restored
    cout << "List after check: ";
    print(head);

    return 0;
}
