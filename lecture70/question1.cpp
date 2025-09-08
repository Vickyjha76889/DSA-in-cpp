// valid binary search tree
#include<iostream>
#include<climits>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* insertintobst(node* root, int data){
    if(root == NULL){
        root = new node(data);
        return root;
    }

    if(data>root->data){
        root->right = insertintobst(root->right,data);
    }
    else{
        root->left = insertintobst(root->left,data);
    }

    return root;
}

void takeinput(node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertintobst(root, data);
        cin>>data;
    }
}

bool isBST(node* root, int min, int max){
    if(root == NULL){
        return true;
    }

    if(root->data>min && root->data < max){
        bool left  = isBST(root->left,min,root->data);
        bool right = isBST(root->right,root->data,max);
        return left && right;
    }
    else{
        return false;
    }
}

int main(){
    node* root = NULL;
    cout<<"enter the data to create bst";
    takeinput(root);
    bool ans = isBST(root,INT_MIN,INT_MAX);
    if(ans){
        cout<<"THE GIVEN IS VALID BST";
    }

}