// height of the tree
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
        this ->right = NULL;
    }

};

void levelordertraveral(node* root){

    queue<node*>q;
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


node* buildtree(node* &root){
    queue<node*>q;
    cout<<"Enter the data\n";
    int data;
    cin>>data;
    root  = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter the data for left"<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter the data for right"<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
    return root;
}

int height(node* root){
    if(root == NULL){
        return 0;
    }

    int left = height(root -> left);
    int right = height(root -> right);

   int ans = max(left,right) + 1 ;
   return ans;
}

int main(){
    node* root = NULL;
    root = buildtree(root);
    levelordertraveral(root);           
    int h = height(root) ;
    cout<<"height of the tree is: "<<h;

}