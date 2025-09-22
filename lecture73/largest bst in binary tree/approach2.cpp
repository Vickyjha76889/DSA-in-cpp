// largest bst in a binary tree
#include<iostream>
#include<climits> 
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


node* buildtree(node* &root){
    cout<<"enter the data";
    int data;
    cin>>data;
    
    if(data == -1){
        return  NULL;
    }

    root = new node(data);

    cout<<"Enter the data for left  ";
    root->left =  buildtree(root->left);

    cout<<"Enter the right data for "<<root->data;
    root->right =  buildtree(root->right);

    return root;
}

class info{
    public:
    int maxi;
    int mini;
    bool isbst;
    int size;
};

info solve(node* root, int &ans){
    if(root == NULL){
        return {INT_MIN, INT_MAX,true,0};
    }

    info left = solve(root->left,ans);
    info right = solve(root->right,ans);

    info currnode;
    currnode.size = left.size + right.size + 1;
    currnode.maxi = max(root->data,right.maxi);
    currnode.mini = min(root->data,left.mini);

    if(left.isbst && right.isbst && (root->data > left.maxi && root->data<right.mini)){
        currnode.isbst = true;
    }else{
        currnode.isbst = false;
    }

    if(currnode.isbst){
        ans = max(ans,currnode.size);
    }

    return currnode;
}

int largestbst(node* root){
    int maxsize = 0;
    info temp = solve(root,maxsize);

    return maxsize;
}


int main(){
    node* root = NULL;
    root = buildtree(root);
    int ans = largestbst(root);
    cout<<"largest bst size : "<<ans;
}