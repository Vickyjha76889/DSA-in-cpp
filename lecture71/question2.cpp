// flatten a BST into a sorted linked list
#include<iostream>
#include<queue>
#include<vector>
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

class node1{
    public:
    int data;
    node1* next;

    node1(int data){
        this->data = data;
        this->next = NULL;
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
void inorder(node* root, vector<int>& arr){
    if(root == NULL){
        return ;
    }
    inorder(root->left , arr);
    arr.push_back(root->data);
    inorder(root->right, arr);

}

void insertintohead(node1* &head , int data){
    if(head == NULL){
        node1* temp = new node1(data);
        head = temp;
    }
    else{
        node1* temp = new node1(data);
        temp->next = head;
        head = temp;
    }
}

void BSTintoLL(node* root, node1* &list){
    vector<int> arr;
    inorder(root,arr);
    int i = arr.size()-1;
    while(i >= 0){
        int data = arr[i];
        insertintohead(list,data);
        i--;
    }
}

void traversalLL(node1* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}


int main(){
    node* root = NULL;
    node1* list = NULL;
    cout<<"ENTER THE DATA FOR THE BST\n";
    takeinput(root);
    traversal(root);
    BSTintoLL(root,list);
    cout<<"THE TRAVERSAL OF THE LINKED LIST IS :";
    traversalLL(list);
    return 0;
}