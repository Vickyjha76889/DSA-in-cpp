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

void find(node* &root, int data){
    if(data == root->data || root == NULL){
        cout<<"found the element";
        return ;
        
    }

    if(data > root->data){
        find(root->right, data);
    }
    else{
        find(root->left,data);
    }
}

void traversal(node* &root){
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

node* insertintoBST(node* root,int data){
    if(root == NULL){
        root = new node(data);
        return root;
    }

    if(data>root->data){
         root->right = insertintoBST(root->right,data);
    }
    else{
       root->left = insertintoBST(root->left,data);
    }

    return root;
}

void takeinput(node* &root){
    int data;
    cin>>data;

    while(data != -1){
       root =  insertintoBST(root,data);
        cin>>data;
    }
}

int main(){
    node* root = NULL;
    cout<<"enter the data\n";
    takeinput(root);
    traversal(root);
    find(root,15);
   
}