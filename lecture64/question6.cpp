// left view of binary tree


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


void solve(node* root,vector<int> &ans, int lvl){
    if(root == NULL){
        return;
    }
    if(lvl == ans.size()){  // if the level is equal to the size of ans, it means we are at a new level
        ans.push_back(root->data);
    }

    solve(root->left,ans,lvl+1);
    solve(root->right,ans,lvl+1);
}

vector<int> leftview(node* root){
    vector<int> ans;
    solve(root,ans,0);
    return ans;
}

int main(){
    node* root = NULL;
    createTree(root);
    vector<int> res = leftview(root);
    for(auto i:res){
        cout<<i<<" "; 
    }
    cout<<endl;
    
}
