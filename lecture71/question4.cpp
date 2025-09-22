#include<iostream>
#include<queue>
#include<vector>
#include <climits>
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
void inorder(node* root, vector<int>& arr){
    if(root == NULL){
        return ;
    }
    inorder(root->left , arr);
    arr.push_back(root->data);
    inorder(root->right, arr);

}

node* solve(vector<int> &arr, int mini , int maxi ,int& i){
    if(i>= arr.size())
        return NULL;

    if(arr[i] < mini || arr[i] > maxi){
    return NULL;
    }

    
    node* root1 = new node (arr[i++]);

    root1->left = solve(arr,mini,root1->data,i);
    root1->right = solve(arr,root1->data,maxi,i);

    return root1;
    
}

node* preorder(vector<int> arr){
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(arr,mini,maxi,i);
}

int main(){
    vector<int> arr = {20,10,5,15,13,35,30,42};
    node* root =  preorder(arr);
    traversal(root);
    return 0;
}