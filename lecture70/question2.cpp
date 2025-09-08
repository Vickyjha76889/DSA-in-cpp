// kth smallest element BST
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
int solve(node* root, int &i, int k){
    if(root == NULL){
        return -1;
    }

    int left = solve(root->left , i , k);

    if(left != -1){
        return left;
    }

    i++;
    if(i == k){
        return root->data;
    }

    return solve(root->right,i,k);
}

int main(){
    node* root = NULL;
    cout<<"enter the data to create bst";
    takeinput(root);
    int i = 0;
    int ans = solve(root,i,3);
    cout<<ans;
}