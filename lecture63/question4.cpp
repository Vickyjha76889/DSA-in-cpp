// question 4 check two identical trees

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

bool identical(node* r1, node* r2){
    if(r1 == NULL && r2 == NULL){
        return true;
    }

    if(r1 == NULL && r2 != NULL){
        return false;
    }

    if(r1 != NULL && r2 == NULL){
        return false;
    }

    bool left   = identical(r1->left , r2->left);
    bool right  = identical(r1->right , r2->right);

    if(r1->data == r2->data ){
        return true;
    }
    else{
        return false;
    }

}

int main(){
    node* r1= NULL;
    buildtree(r1);
    node* r2 = NULL;
    buildtree(r2);
    traversal(r2);
    traversal(r1);
    bool isidentical = identical(r1,r2);
    cout<<"is identical ?"<<(identical? "yes" : "no")<<endl; 
    

}