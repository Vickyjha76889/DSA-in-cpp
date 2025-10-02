//question 2  isHeap in this question we have to tell that is the given tree is heap or not

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

void buildtree(node* &root){
    queue<node*> q;
    cout<<"enter the data for root node"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        cout<<"enter the left node for "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter the right node for "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

int count(node* root , int index){
    if(root == NULL){
        return 0;
    }

    return 1 + count(root->left,index+1) + count(root->right,index+1);
}

bool isCbt(node* root, int i, int n ){
    if(root == NULL){
        return true;
    }
    if(i>=n){
        return false;
    }
    else{
        bool left = isCbt(root->left,2*i+1,n);
        bool right = isCbt(root->right,2*i+2,n);
        return (left && right);
    }
}

bool isMaxheap(node* root){
    if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL) return true;
    if(root->right == NULL){ 
        return (root->data > root->left->data);
    }else{
        bool left = isMaxheap(root->left);
        bool right = isMaxheap(root->right);

        return (left && right) && (root->data > root->left->data) && (root->data > root->right->data);
    }
}



bool isHeap(struct node* root){
    int index  = 0;
    int Tcount = count(root,index);
    if(isCbt(root,index,Tcount) && isMaxheap(root)){
        return true;
    }
    else{
        return false;
    }
}

// bool isCbt(struct node* root,int n,int i){
//     if(i>=n){
//         return true;
//     }
//     bool left = isCbt(arr,n,i+1);
//     bool right = isCbt(arr,n,i+1);

// }

int main(){
    node* root = NULL;
    buildtree(root);
    bool ans = isHeap(root);
    if(ans){
        cout<<"The given tree is Heap"<<endl;
    }else{
        cout<<"THE given tree is not heap"<<endl;
    }

}