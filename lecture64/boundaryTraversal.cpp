#include<iostream>
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

void createTree(node* &root){
    queue<node*>q;
    cout<<"enter the data\n";
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node * temp = q.front();
        q.pop();

        cout<<"Enter the data for left "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter the data for right "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }

    }
}

// my version code by my own 

void isleaf(node* root){
    return(root->left == NULL && root->right == NULL);
}

void inorder(node*root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    if(root->left == NULL || root->right == NULL){
        cout<<root->data<<" ";
    }
    inorder(root->right);
}

void leftonly(node* root){
    if(root->left == NULL || ifleaf(root)){
        return;
    }
    cout<<root->data<<" ";
    if(leftonly) (root->left);
    
}

void rightonly(node* root){
    if(root->right == NULL){
        return;
    }
    rightonly(root->right);
    if(root != NULL ){
        cout<<root->data<<" ";
    }
}

void boundarytraversal(node* root){
    cout<<root->data<<" ";
    leftonly(root->left);
    inorder(root);
    rightonly(root->right);
}

// void isleaf(node* root){
//     return (root->left == NULL && root->right == NULL);
// }

// void printleftboundary(node* root){
//     node* curr = root->left;
//     while(curr){}
//         if(!isleaf())
//         cout<<curr->data<<" ";
//         if(curr->left)
//         curr = curr->left;
//     }
// }

// void printleaf(node* root){
//     if(root == NULL){
//         return;
//     }
//     if(isleaf()){
//         cout<<root->data<<" ";
//     }
//     printleaf(curr->left);
//     printleaf(curr->right);
// }

// void printrightboundary(node*root){
// 
// }


int main(){
    node* root = NULL;
    createTree(root);
    boundarytraversal(root);
    

}
