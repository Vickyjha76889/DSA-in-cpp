#include<iostream>
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

vector<int> zigzagTraversal(node* root){
    vector<int> result;
    if(root == NULL){
        return result;
    }

    queue<node*> q;
    q.push(root);

    bool lefttoright = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size);
        
        for(int i =0; i<size ;i++){
            node* frontNode  = q.front();
            q.pop();

            int index = lefttoright ? i : size-i-1;

            ans[index] = frontNode->data;

            if(frontNode->left){
                q.push(frontNode->left);
            }

            if(frontNode->right ){
                q.push(frontNode->right);
            }
        }

        lefttoright = !lefttoright;

        for(int i: ans){
            result.push_back(i);
            cout<<i<<" ";
        }

        cout<<endl;
    }
    return result;

}

void buildTree(node* &root){
    queue<node*> q;
    cout<<"enter the data ";
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter the data for left"<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter the data for right"<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

// vector<int> zigzagTraversal(node* root){
//     vector<int> result;
//     if(root == NULL)
//        return result;
     
//     queue<node*> q;
//     q.push(root);
//     bool lefttoright = true;
     
//     while(!q.empty()){
//         int size = q.size();
//         vector<int> ans(size);
//         for(int i = 0; i<size ; ++i){
//             node* frontend = q.front();
//             q.pop();

//             int index = lefttoright? i: size-i-1;
//             ans[index] = frontend->data;

//             if(frontend->left){
//                 q.push(frontend->left);
//             }
//             if(frontend->right){
//                 q.push(frontend->right);
//             }            
//         }

//         lefttoright = !lefttoright;

//         for(int val: ans){
//                 result.push_back(val);
//                 cout<<val<<" ";
//         }
//             cout<<endl;
//     }    
//     return result;
// }

int main(){
    node* root = NULL;
    buildTree(root);
    zigzagTraversal(root);

}