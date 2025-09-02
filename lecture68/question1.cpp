// morish traversal

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

void morrisTraversal(Node* root) {
    Node* curr = root;

    while (curr != NULL) {
        if (curr->left == NULL) {
            // No left child → print and move right
            cout << curr->data << " ";
            curr = curr->right;
        } else {
            // Find inorder predecessor
            Node* pred = curr->left;
            while (pred->right != NULL && pred->right != curr) {
                pred = pred->right;
            }

            if (pred->right == NULL) {
                // Make a thread
                pred->right = curr;
                curr = curr->left;
            } else {
                // Thread already exists → remove it
                pred->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

int main() {
   

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Morris Inorder Traversal: ";
    morrisTraversal(root);

    return 0;
}
