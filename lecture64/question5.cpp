// bottom view 

// top tree of binray tree;

#include<iostream>
#include<map>
#include<vector>
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

void createTree(node* &root){
    queue<node*>q;
    cout<<"enter the data\n";
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node * temp = q.front();
        q.pop();

        cout<<"Enter the data for left "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter the data for right "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }

    }
}

// my version code by my own 

bool isleaf(node* root){
    return(root->left == NULL && root->right == NULL);
}

void inorder(node*root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    if(root->left == NULL || root->right == NULL){
        cout<<root->data<<" ";
    }
    inorder(root->right);
}

void leftonly(node* root){
    if(root->left == NULL || isleaf(root)){
        return;
    }
    cout<<root->data<<" ";
    if(root->left){
    leftonly(root->left);
    }
    else{
        leftonly(root->right);
    } 
    
}

void rightonly(node* root){
    if(root->right == NULL || isleaf(root)){
        return;
    }


    if(root->right){
        rightonly(root->right);
    }
    else{
        rightonly(root->left);
    }
    
    cout<<root->data<<" ";
    
}

void boundarytraversal(node* root){
    cout<<root->data<<" ";
    leftonly(root->left);
    inorder(root);
    rightonly(root->right);
}

// void isleaf(node* root){
//     return (root->left == NULL && root->right == NULL);
// }

// void printleftboundary(node* root){
//     node* curr = root->left;
//     while(curr){}
//         if(!isleaf())
//         cout<<curr->data<<" ";
//         if(curr->left)
//         curr = curr->left;
//     }
// }

// void printleaf(node* root){
//     if(root == NULL){
//         return;
//     }
//     if(isleaf()){
//         cout<<root->data<<" ";
//     }
//     printleaf(curr->left);
//     printleaf(curr->right);
// }

// void printrightboundary(node*root){
// 
// }

vector<int> bottomview(node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    map<int,int> topnode;
    queue<pair<node*,int>> q;

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<node*,int> temp = q.front();
        q.pop();

        node*frontnode = temp.first;
        int hd = temp.second;

        topnode[hd] = frontnode->data;


        if(frontnode->left)
        q.push(make_pair(frontnode->left,hd-1));
        
        if(frontnode->right)
        q.push(make_pair(frontnode->right,hd+1));
    }
    for(auto i: topnode){
        ans.push_back(i.second);
    }
    return ans;
}



// this is for the leaf node only bottom view is not a good approach

// void bottomview(node* root){
    
//     if(root == NULL){
//         return;
//     }

//    bottomview(root->left);

//    if(root->left == NULL && root->right == NULL){
//     cout<<root->data<<" ";
//    }

//    bottomview(root->right);

// }

int main(){
    node* root = NULL;
    createTree(root);
    vector<int> res = bottomview(root);
    for(auto i:res){
        cout<<i<<" "; 
    }
    cout<<endl;
    
}
