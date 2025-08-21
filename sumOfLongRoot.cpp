
// sum of the longest bloodline of a tree(sum of nodes of -
//-longest path from root to leaf nodes)

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

node* buildtree(node* root){
    cout<<" Enter the data ";
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }


    root = new node(data);

    cout<<" Enter the data for left "<<root->data<<endl;
    root->left = buildtree(root->left);

    cout<<" Enter the data for right "<<root->data<<endl;
    root->right = buildtree( root->right );

    return root;

}

void buildtree2(node* &root){
    queue<node*> q;
    cout<<"enter the data for root"<<endl;
    int data;
    cin>>data;
    root= new node(data);
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

void solve(node* root, int len, int sum , int &maxlen, int &maxsum){
    if(root == NULL){
        if(len > maxlen){
            maxlen = len;
            maxsum = sum;
        }else if(len == maxlen){
            maxsum = max(sum, maxsum);
        }
        return;
    }

    sum = sum + root->data;
    solve(root->left,len+1,sum,maxlen,maxsum);
    solve(root->right,len+1,sum,maxlen,maxsum);

}

int sumoflongroot(node* root){
    int len = 0;
    int maxlen = 0;
    
    int sum = 0;
    int maxsum = 0;
    solve(root,len, sum, maxlen, maxsum);
    return maxsum;
}

int main(){

    node*root = NULL;
    buildtree2(root);
    int result = sumoflongroot(root);
    cout<<"The sum of the longest bloodline is :"<<result<<endl;
    return 0;

}