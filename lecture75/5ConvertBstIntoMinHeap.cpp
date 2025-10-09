//convert BST into MINHEAP

#include<iostream>
#include<queue>
#include<vector>
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

node* insertintoBst(node* root,int data){
    if(root == NULL){
        return new node(data);
    }
    if(data > root->data){
        root->right = insertintoBst(root->right,data);
    }
    else if(data < root->data){
        root->left = insertintoBst(root->left,data);
    }
    return root;
}

void takeinput(node* &root){
    int data;
    cin>>data;
    
    while(data != -1){
        root = insertintoBst(root,data);
        cin>>data;
    }

}

void traverseInorder(node* root){
    if(root == NULL){
        return ;
    }
    traverseInorder(root->left);
    cout<<root->data<<" "<<endl;
    traverseInorder(root->right);
}

// void convertbstIntoMinheap(node* root,vector<int> &inorder){
//     if(arr.size() == 0){
//         return;
//     }
//     root->data = arr.front();
//     arr.erase(arr.begin());
//     if(root->left){
//         convertbstIntoMinheap(root->left,inorder);
//     }
//     if(root->right){
//         convertbstIntoMinheap(root->right,inorder);
//     }
// }



void convertbstIntoMinHeap(node* &root,int arr[],int &i){ // this is the correct approach
    if(!root){
        return;
    }
    root->data = arr[i++];
    convertbstIntoMinHeap(root->left,arr,i);
    convertbstIntoMinHeap(root->right,arr,i);
}

void traverse(node* root){
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

int main(){

    node* root = NULL;
    cout<<"enter the data for root node"<<endl;
    takeinput(root);
    traverseInorder(root);
    traverse(root);
    cout<<endl;

    return 0;

}