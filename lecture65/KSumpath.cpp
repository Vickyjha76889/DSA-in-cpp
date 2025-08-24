// given the binary tree and integer k find 
//the no of paths which sum is equal to k

#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void buildtree(node* &root){
    cout<<"Enter the root\n";
    int data;
    cin>>data;
    root = new node(data);
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        

        cout<<"Enter the left node of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter the right node of "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }

    }
}

void solve(node* root, int k, vector<int> path, int &count){
    if(root == NULL){
        return;
    }

    path.push_back(root->data);

    solve(root->left, k, path, count);
    solve(root->right, k , path, count);

    int sum = 0;
    int size = path.size();
    for(int i = size-1;i>=0; i--){
        sum += path[i];
        if(sum == k){
            count++;
        }
    }

    path.pop_back();
}

int sumk(node* root, int k){
    vector<int> path;
    int count = 0;
    solve(root,k, path,count);
    return count;
}



int main(){
    node* root = NULL;
    buildtree(root);
    int k  = sumk(root,4);

    cout<<"the no the the path are "<<k<<endl;


    return 0;
}