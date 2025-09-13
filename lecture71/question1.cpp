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

//brute force;
bool twosum(node* root , int target){
    vector<int> arr;
    inorder(root, arr);

    for(int i = 0 ; i<arr.size();i++){
        for(int j = i+1 ; j<arr.size();j++){
            if(arr[i] + arr[j] == target){
                return true;
            }
        }
    }

    return false;
}

// with better  ..time complexity O(n)
bool twosuminBST(node* root , int target){
    vector<int> arr;
    inorder(root, arr);
    int i = 0;
    int j = arr.size()-1;
    // int sum = 0;

    while(i<j){
        int sum = arr[i] + arr[j];
        if(sum == target){
            return true;
        }
        else if(sum < target){
            i++;
        }
        else{
            j--;
        }
    }

    return false;

}

int main(){
    node* root = NULL;
    cout<<"ENTER THE DATA FOR THE BST\n";
    takeinput(root);
    traversal(root);
    cout<<"ENTER THE TARGET \n";
    int target;
    cin>>target;
    bool ans = twosuminBST(root,target);
    if(ans){
        cout<<"THE SUM OF THE TARGET IS FOUND";
    }else{
        cout<<"NOT FOUND";
    }

    return 0;
}