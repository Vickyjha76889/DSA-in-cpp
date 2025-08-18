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
vector<int> verticalorder(node* root){
    map<int,map<int,vector<int>>> nodes;
    queue<pair<node*,pair<int,int> > >q;
    vector<int> ans;
    if(root == NULL)
       return ans;

    q.push(make_pair(root,make_pair(0,0)));
    while(!q.empty()){
        pair<node*,pair<int, int>> temp = q.front();
        q.pop();
        node* frontnode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontnode->data);

        if(frontnode->left){
            q.push(make_pair(frontnode->left,make_pair(hd-1,lvl+1)));
        }
        if(frontnode->right){
            q.push(make_pair(frontnode->right,make_pair(hd+1,lvl+1)));
        }

    }

    for(auto i : nodes){
        for(auto j : i.second){
            for(auto k: j.second){
                ans.push_back(k);
            }
        }
    }

    return ans;

}


int main(){
    node* root = NULL;
    createTree(root);
    vector<int> res = verticalorder(root);
    for(int val : res) cout << val << " ";
    cout << endl;
    
    

}
