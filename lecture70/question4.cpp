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

node* insertelement(node * root , int data){
    if(root == NULL){
        root = new node(data);
        return root;
    }
     if(data>root->data){
        root->right = insertelement(root->right,data);
     }
     else{
       root->left = insertelement(root->left,data);
     }

     return root;
}

void takeinput(node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertelement(root , data);
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
        }else{
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

pair<int, int> prodessorSuccessor(node* root, int key){

    node* temp = root;
    int pred = -1;
    int succ = -1;

    while(temp->data != key && temp->data != NULL){
        if(temp->data < key){
            pred = temp->data;
            temp = temp->left;
        }
        else{
            succ = temp->data;
            temp=temp->left;
        }
    }

    if(temp == NULL) return make_pair(pred, succ);

    node* leftdata = temp->left;
    while(leftdata->left != NULL ){
        pred = leftdata->data;
        leftdata = leftdata->left;
    }

    node* rightdata = temp->right;
    while(rightdata->right != NULL ){
        succ = rightdata->data;
        rightdata = rightdata->right;
    }

    pair<int, int> ans = make_pair(pred,succ);
    
    return ans;

}


int main(){
    node* root = NULL;
    cout<<"ENTER THE DATA FOR THE BST\n";
    takeinput(root);
    traversal(root);
    pair<int,int> PS = prodessorSuccessor(root, 10);
    cout << "Predecessor: " << PS.first << ", Successor: " << PS.second << endl;

}