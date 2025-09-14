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

// node* NbstTOBalanceBst(node* &root){
//     vector<int>arr;
//     inorder(root,arr);
//     int S = arr.size();
//     int s = S/2;
//     int a = s-1;
//     int b = s+1;
//     node* root1 = NULL;
//     createBST(root1,arr[s]);
//     while(a >= 0){
//         createBST(root1,arr[a]);
//         a--;
//     }

//     while(b < S){
//         createBST(root1,arr[b]);
//         b++;
//     }

//     return root1;

// }
 node* sortedArrayToBST(vector<int> arr , int s, int e){

    if(s>e){
        return NULL;
    }

    int mid = (s + e) / 2;
    node* root1 = new node (arr[mid]);

    root1->left = sortedArrayToBST(arr,s,mid-1);
    root1->right = sortedArrayToBST(arr,mid+1,e);

    return root1;

 }

node* NbstTOBalanceBst(node* &root){
    vector<int>arr;
    inorder(root,arr);

    return sortedArrayToBST(arr,0,arr.size()-1);
}


int main(){
    node* root = NULL;
    cout<<"ENTER THE DATA FOR THE BST\n";
    takeinput(root);
    traversal(root);
    node* balancedRoot = NbstTOBalanceBst(root);
    traversal(balancedRoot);
    return 0;
}