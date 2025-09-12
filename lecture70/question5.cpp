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

node* createBST(node* &root, int data){
    if(root == NULL){
        root = new node(data);
        return root;
    }

    if(root->data > data){
        root->left = createBST(root->left,data);
     }
     else{
        root->right = createBST(root->right, data);
     }

     return root;
}

void takeinput(node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = createBST(root, data);
        cin>>data;
    }
}

void traversal(node* root){
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

node* LCAinBST(node* root, int p , int q){
    if(root == NULL){
        return NULL;
    }

    if(root->data > p && root->data > q){
        return LCAinBST(root->left,p , q);
    }

    if(root->data < p && root->data < q){
        return LCAinBST(root->right,p ,q);
    }

    return root;
}


int main(){
    node* root = NULL;
    cout<<"ENTER THE DATA FOR THE BST\n";
    takeinput(root);
    traversal(root);

    int p;
    cout<<"ENTER THE DATA FOR P ";
    cin>>p;

    int q;
    cout<<"ENTER THE DATA FOR q ";
    cin>>q;

    node* ans = LCAinBST(root, p, q);
    if(ans != NULL)
        cout << "THE LCA IS : " << ans->data;
    else
        cout << "LCA not found";


    return 0;
}