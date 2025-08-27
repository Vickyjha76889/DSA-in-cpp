// construct tree from inorder and postorder traversal

#include<iostream>
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

int findpostion(int in[] , int element , int n){
    for(int i = 0; i < n; i++){
        if(in[i] == element){
            return i;
        }
    }
    return -1;
}

node* solve(int in[] , int post[], int &index , int s, int e , int n){
    if(index < 0 || s > e){
        return NULL;
    }

    int element = post[index--];
    node* root = new node(element);
    int postion = findpostion(in, element ,  n);

    root->right = solve(in, post , index, postion + 1, e ,n);
    root->left = solve(in, post , index, s, postion -1,n);

    return root;
}

node* buildtree(int in[], int post[], int n){
    int index = n-1;
    node* ans = solve(in,post,index,0,n-1,n);
    return ans;
}

void printtree(node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    printtree(root->left);
    printtree(root->right);
}

int main(){
    int in[] = {4,2,5,1,6,3,7};
    int post[] = {4,5,2,6,7,3,1};
    int n = 7;

    node* root = buildtree(in,post,n);

    printtree(root);

    return 0;
} 