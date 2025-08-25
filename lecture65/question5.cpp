// maximum sum of non-adjacent nodes in a binary tree

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
pair<int, int>solve(node* root){
     if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
     }

     pair<int, int>left = solve(root->left);
     pair<int, int>right = solve(root->right);

     pair<int, int> res;

     res.first = root->data + left.second + right.second;

     res.second = max(left.first,left.second) + max(right.first, right.second);

     return res;
}
int getMaxSum(node* root){
    pair<int,int> ans = solve(root);
    return max(ans.first, ans.second);

}

int main(){
    node* root = NULL;
    buildtree(root);

    int ans = getMaxSum(root);
    cout<<"the max of non-adjacent nodes is : " <<ans<<endl;
}