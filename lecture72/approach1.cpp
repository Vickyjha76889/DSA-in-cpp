#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* createBST(node* root, int data) {
    if (root == NULL) {
        root = new node(data);
        return root;
    }

    if (data < root->data) {
        root->left = createBST(root->left, data);
    } else {
        root->right = createBST(root->right, data);
    }

    return root;
}

void takeinput(node*& root) {
    int data;
    cin >> data;

    while (data != -1) {
        root = createBST(root, data);
        cin >> data;
    }
}

void traversal(node* root) {
    if (!root) return;

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";

            if (temp->left) {
                q.push(temp->left);
            }

            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void inorder(node* root, vector<int>& arr) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

vector<int> inorder1(node* root) {
    vector<int> arr;
    inorder(root, arr);
    return arr;
}

// Merge two sorted arrays
vector<int> merge(vector<int> arr1, vector<int> arr2) {
    vector<int> arr;
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            arr.push_back(arr1[i]);
            i++;
        } else {
            arr.push_back(arr2[j]);
            j++;
        }
    }

    while (i < arr1.size()) {
        arr.push_back(arr1[i]);
        i++;
    }

    while (j < arr2.size()) {
        arr.push_back(arr2[j]);
        j++;
    }

    return arr;
}

// Build balanced BST from sorted array
node* buildBalancedBST(vector<int>& arr, int start, int end) {
    if (start > end) return NULL;

    int mid = (start + end) / 2;
    node* root = new node(arr[mid]);

    root->left = buildBalancedBST(arr, start, mid - 1);
    root->right = buildBalancedBST(arr, mid + 1, end);

    return root;
}

int main() {
    node* root1 = NULL;
    node* root2 = NULL;

    cout << "Enter elements for BST1 (-1 to stop): ";
    takeinput(root1);

    cout << "Enter elements for BST2 (-1 to stop): ";
    takeinput(root2);

    vector<int> arr1 = inorder1(root1);
    vector<int> arr2 = inorder1(root2);

    vector<int> arr = merge(arr1, arr2);

    node* root = buildBalancedBST(arr, 0, arr.size() - 1);

    cout << "Level Order Traversal of Merged Balanced BST:" << endl;
    traversal(root);

    return 0;
}
