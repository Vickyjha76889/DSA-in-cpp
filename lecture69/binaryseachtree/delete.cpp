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

node* min(node* &root ){
    if(root == NULL){
        return NULL;
    }
    node* current = root;
    while(current->left != NULL){
        current = current->left;
    }

    return current;
}

node* max(node* &root ){
    if(root == NULL){
        return NULL;
    }
    node* current = root;
    while(current->right != NULL){
        current = current->right;
    }

    return current;
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
node* deletefrombst(node* root, int key){
     
    // base case
    if(root == NULL){
        return NULL;
    }

    if(root->data == key){
        
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // if one child
            // if have left child
            if(root->left != NULL && root->right == NULL){
                node* temp = root->left;
                delete root;
                return temp;
            }

            // if having right child 
            if(root->left == NULL && root->right != NULL){
                node* temp = root->right;
                delete root;
                return temp;
            }
        
        // if having two child
        if(root->left != NULL && root ->right != NULL){
            node* mini = min(root->right);
            root->data = mini->data;
            root->right = deletefrombst(root->right, mini->data);
            return root;
        }


    }
    else{
        if(key < root->data){
            root->left = deletefrombst(root->left,key);
        }
        else{
            root->right = deletefrombst(root->right, key);
        }
        return root;
    }

    return root;
}
int main(){
    node* root = NULL;
    cout<<"enter the data\n";
    takeinput(root);
    traversal(root);
    root = deletefrombst(root,20);
    traversal(root);
}