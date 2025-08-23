//  lowest common ancestor
#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void buildtree(node* &root){
    cout<<"Enter the root\n";
    int data;
    cin>>data;
    root = new node(data);
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        

        cout<<"Enter the left node of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter the right node of "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }

    }
}

node* lca(node* root, int n1 , int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    node* leftans = lca(root->left,n1,n2);
    node* rightans = lca(root->right,n1,n2);

    if(leftans != NULL && rightans != NULL){
        return root;
    }
    else if(leftans != NULL && rightans == NULL){
        return leftans;
    }
    else if(leftans == NULL && rightans != NULL){
        return rightans;
    }
    else{
        return NULL;
    }

}

int main(){
    node* root = NULL;
    buildtree(root);

    cout<<"Enter the two nodes you want to find the lca of\n "; 
    int n1, n2;
    cin>>n1>>n2;

    cout<<"LCA is "<<lca(root,n1,n2)->data<<endl;
    return 0;
}