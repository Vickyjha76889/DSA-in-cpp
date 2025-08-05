#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

};

node* buildtree(node* root){

    cout<<" Enter the data ";
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }
    
    root = new node(data);

    cout<<"enter the data for left "<<data<<endl;
    root->left = buildtree(root -> left);

    cout<<"enter the data for right "<<data<<endl;
    root->right = buildtree(root -> right);

    return root;

} 

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        } 
        else{
            cout<<temp->data<<" ";
            if(temp->left){
               q.push(temp->left);
            }

            if(temp->right){
               q.push(temp->right);
            }
        }

       
    }
}

void inorder(node* root){
    if(root == NULL){
        return;
    }

    inorder(root -> left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root -> left);
    preorder(root->right);
}

void postorder(node* root){
    if(root == NULL){
        return;
    }

    postorder(root -> left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){

    node* root = NULL;
    root = buildtree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 14 -1 -1 -1
    cout<<"the traveral of the root: "<<endl;
    levelOrderTraversal(root);
    cout<<"The inorder traversal : ";
    inorder(root);
    cout<<"\nThe preorder traversal : ";
    preorder(root);
    cout<<"\nThe preorder traversal : ";
    postorder(root);


}