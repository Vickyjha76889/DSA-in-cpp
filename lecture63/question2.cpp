#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void Buildtree(node* &root){
    queue<node*>q;
    cout<<"Enter the data for root\n";
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter the data for left "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter the data for right "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

void levelordertrversal(node* root){
    queue<node* >q;
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

int height(node* root){
    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);
    int h = max(left,right) + 1;

    return h;
}


// #approach1 for finding the width
int diameter(node* root){
    if(root == NULL){
        return 0;
    }

    int opt1 = diameter(root->left);
    int opt2 = diameter(root->right);
    int opt3 = height(root->left) + height(root->right) + 1;

   int w =  max(opt1, max(opt2,opt3));
   return w;
}

// approach 2
pair<int,int> diameterfast(node* root){
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameterfast(node->left);
    pair<int,int> right = diameterfast(node->right);

    int opt1 = left.first;
    int opt2 = right.first;
    int opt3 = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first = max(opt1,max(opt2,opt3));
    ans.second = max(left.second, right.second);

    return ans;
}

int main(){
    node* root = NULL;
    Buildtree(root);
    levelordertrversal(root);
    int W = diameter(root);
    cout<<"diameter of the tree :"<<W;

}