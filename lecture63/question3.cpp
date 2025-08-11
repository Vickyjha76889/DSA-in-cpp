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
    this->right = NULL;
    this->left = NULL;
    }

};


void buildtree(node* &root){
    queue<node*>q;
    cout<<"Enter the data for node\n";
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        cout<<"enter the data for left"<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter the data for right"<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp->right = new node(rightdata);
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

int height(node* root){
    if(root == NULL){
        return 0;
    }

    int leftheight =  height(root->left);
    int rightheight = height(root->right);

    int ans = max ( leftheight , rightheight) + 1;

    return ans;
}



// approach 1 
bool isbalance(node* root){
    if(root == NULL){
        return true;
    }

    bool right = isbalance(root->right);
    bool left = isbalance(root->left);

    bool diff = abs( height(root->left) - height(root->right) ) <=1;
    
    if(left == true && right == true && diff == true){
        return true;
    }else{
        return false;
    }

}

  //approach 2       # time complexity is 0(n);
pair<bool ,int> isbalancefast(node* root){
    if(root == NULL){
        pair<bool , int> p = make_pair(true,0);
        return p;
    }

    pair<bool , int> left = isbalancefast(root->left);
    pair<bool, int> right = isbalancefast(root->right);
    
    bool leftans  = left.first;
    bool rightans = right.first;

    bool diff =  abs (left.second - right.second) <=1;

    pair<bool , int> ans;
    ans.second = max(left.second , right.second) + 1;
    
    if(leftans && rightans  && diff ){
        ans.first = true;
    }else{
        ans.first = false;
    }

    return ans;
}
bool isbalancenode(node* root){
    return isbalancefast(root).first;
}

int main(){
    node* root = NULL;
    buildtree(root);
    traversal(root);
    bool balance = isbalancenode(root);
   cout << "Is it a balanced tree? " << (balance ? "Yes" : "No") << "\n";

    return 0;

}

