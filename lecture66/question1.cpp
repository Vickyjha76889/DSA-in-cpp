// construct tree from inorder and preorder traversals
#include <iostream>
#include<queue>
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

int findposition(int in[] , int element , int n){
    for(int i =0; i<n; i++){

        if(in[i] == element){
            return i;
        }

    }
    return -1;
}

node * solve(int in[] , int pre[], int &index, int s, int e , int n){
    // base case
    if(index >= n|| s > e ){
        return NULL;
    }

    int element = pre[index++];
    node* root = new node(element);
    int position = findposition(in,element,n);

    root->left = solve(in,pre,index,s,position-1,n);

    root->right = solve(in,pre,index, position+1, e,n);

    return root;
    
}
node* buildtree(int in[] , int pre[] , int n){
    int preoderindex = 0;
    node* ans = solve(in,pre,preoderindex,0,n-1,n);
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
    node* root = NULL;
    int in[] = {1,6,8,7};
    int pre[] = {1,6,7,8};
    int n = 4;
     root = buildtree(in,pre,n);

     printtree(root);

    return 0;
}
