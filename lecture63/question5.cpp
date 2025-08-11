// sum of the tree

#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node*right;
    node* left;

    node(int d){
        this->data = d;
        this->right  = NULL;
        this->left = NULL;
    }

};

void buildtree(node* &root){
    queue<node*> q;
    cout<<"enter the data for root\n";
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter the data for left "<<temp->data<<"\n";
        int left;
        cin>>left;

        if(left != -1 ){
            temp->left = new node(left);
            q.push(temp->left);
        }

        cout<<"Enter the data for right"<<temp->data<<"\n";
        int right;
        cin>>right;

        if(right != -1){
            temp->right = new node(right);
            q.push(temp->right);
        }
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

pair<bool,int> issumtree(node* root){
    if(root == NULL){
        pair<bool, int> p = make_pair(true,0);
        return p;
    }
    if(root->left == NULL){
        pair<bool,int>p = make_pair(true,root->data);
        return p;
    }
    pair<bool,int> leftans = issumtree(root->left);
    pair<bool,int> rightans = issumtree(root->right);

    bool left = leftans.first;
    bool right = rightans.first;

    bool cond = root->data == leftans.second + rightans.second;

    pair<bool,int> ans;
    
    if(left && right && cond){
        ans.first = true;
        ans.second =2*root->data;
    }
    else{
        ans.first = false;
    }

    return ans;
}
bool issumtreefast(node* root){
    return issumtree(root).first;
}

int main(){
    node* root = NULL;
    buildtree(root);
    traversal(root);
    bool ans  = issumtreefast(root);
    cout<<"issum tree ? "<<(ans? "yes":"no")<<endl;

}