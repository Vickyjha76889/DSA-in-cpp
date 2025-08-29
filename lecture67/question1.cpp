// minium time to burn the entire tree

#include<iostream>
#include<queue>
#include<map>
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

void buildtree(node* &root){
    cout<<"enter the data for root node\n";
    int data;
    cin>>data;
    root = new node(data);
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter left data for : "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp ->left = new node(leftdata);
            q.push(temp->left);
        }

         cout<<"Enter right data for : "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp ->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

node* createparentmappning(node* root , int target , map<node* , node*> &nodetoparent){

    node* res = NULL;
    queue<node* > q;
    q.push(root);
    nodetoparent[root] = NULL;

    while(!q.empty()){
        node* front = q.front();
        q.pop();

        if(front->data == target){
            res = front;
        }

        if(front->left){
            nodetoparent[front->left] = front;
            q.push(front->left);
        }

        if(front->right){
            nodetoparent[front->right] = front;
            q.push(front->right);
        }

    }

    return res;
}

int burntree(node* root , map<node*, node*> &nodetoparent){

    map<node*, bool> visited;
    queue<node*>q ;
    int ans = 0;

    q.push(root);
    visited[root] = 1;
    

    while(!q.empty()){
        bool flag = 0;

        int size = q.size();
        for(int i = 0 ;i< size; i++){
            node* front = q.front();
            q.pop();

            if(front ->left && !visited[front->left]){
            q.push(front->left);
            visited[front->left] = 1;
            flag = 1;
            }

            if(front->right && !visited[front->right]){
                q.push(front->right);
                visited[front->right] = 1;
                flag = 1;
            }

            if(nodetoparent[front] && !visited[nodetoparent[front]]){
                q.push(nodetoparent[front]);
                flag  = 1;
                visited[nodetoparent[front]] = 1;
            }

        }
        if(flag == 1){
            ans++;
        }
    }
    return ans;

}

int minTime(node* root , int target){
    // algo
    // step 1 - create node to parent mapping
    // step 2 - find target node 
    // step 3 - burn the treee in min time 

    map<node* ,node*> nodetoparent ;
    node* targetnode = createparentmappning(root,target, nodetoparent);
    int ans = burntree(targetnode, nodetoparent);
    return ans;

}


int main(){
    node* root = NULL;
    buildtree(root);
    int target = 4;
    cout<<minTime(root,target); 

}