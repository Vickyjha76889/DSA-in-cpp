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


vector<int> inorder1(node* root){
    vector<int> arr;
    inorder(root,arr);
    return arr;
}

node* solve(vector<int> &arr,int mini,int maxi , int& i){

    if(i >= arr.size()){
        return NULL;
    }

   if(arr[i] < mini || arr[i] > maxi){
        return NULL;
    }

    node* temp = new node(arr[i++]);

    temp ->left = solve(arr,mini,temp->data,i);
    temp ->right = solve(arr,temp->data,maxi,i);

    return temp;
}


node* preorder(vector<int> &arr){
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(arr,mini,maxi,i);
 }

 vector<int> merge(vector<int> arr1 , vector<int> arr2){
    vector<int> arr;
    int i = 0;
    int j = 0;
    while(i < arr1.size() && j < arr2.size() ){
        if(arr1[i] > arr2[j]){
            arr.push_back(arr1[i]);
            i++;
        }
        else{
            arr.push_back(arr2[j]);
            j++;
        }
    }

    while(i < arr1.size()){
        arr.push_back(arr1[i]);
        i++;
    }

    while(j < arr2.size()){
        arr.push_back(arr2[j]);
        j++;
    }

    return arr;
 }

 node* buildtree(vector<int> &arr, int s , int e ){
    if(s>e){
        return NULL;
    }    
    int mid = s + (e -s)/2;
    node* root = new node(arr[mid]);

    root->left = buildtree(arr,s,mid-1);
    root->right = buildtree(arr,mid + 1, e);

    return root;
 }
 

int main(){
    node* root1 = NULL;
    node* root2 = NULL;
    takeinput(root1);
    takeinput(root2);

    vector<int> arr1 = inorder1(root1);
    vector<int> arr2 = inorder1(root2);

    vector<int> arr = merge(arr1,arr2);
    node* root = buildtree(arr,0,arr.size());
    traversal(root);
}