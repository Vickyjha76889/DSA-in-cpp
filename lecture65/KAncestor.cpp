// given the binary tree and integer k find 
//the no of paths which sum is equal to k

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

void solve(node* root, int& k, int node){
    if(root == NULL){
        return;
    }

    if(root->data == node){
        return root;
    }

    node* leftans = solve(root->left, k , node);
    node* rightans = solve(root->right,k,node);

    if(leftans != NULL && rightans == NULL){
        k--;
        if(k==0){
            k = INT_MAX;
            return root;
        }
        else{
            return leftans;
        }
    }
    if(rightans != NULL && leftans == NULL){
        k--;
        if(k == 0){
            k = INT_MAX;
            return root;
        }
        else{
            return rightans;
        }
    }
    return NULL;
    
}

int kthAncestor(node* root, int k, int node){
    node* ans = solve(root, k , node);
    if(ans == NULL || ans->data == node){
        retrun -1;
    }
    else{
        return ans->data;
    }
}

int main(){
    node* root = NULL;
    buildtree(root);
    


    return 0;
}