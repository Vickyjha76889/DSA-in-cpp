// MERGE TWO BINARY SEARCH TREE

// STEPS--
    // STEP1 -- CONVERT BST INTO  SORTEDLINKED LIST
    // STEP2 -- MERGE SORTED LINKED LIST
    // STEP3 -- CONVERT  MERGED SORTED LINKEDLIST INTO BST

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

void traversal(node* root ){
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
        }else{
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

node* createbst(node* &root, int data){

    if(root == NULL){
        root = new node(data);
        return root;
    }

    if(data < root->data){
        root->left = createbst(root->left,data);
    }

    if(data > root->data){
        root->right = createbst(root->right,data);
    }

    return root;
}

node* takeinput(node* root){
    int data;
    cin>>data;
    while(data != -1){
        root = createbst(root,data);
        cin>>data;
    }
    return root;
}



// STEP1 convert bst into sorted linkedlist

void convertIntoSortedLL(node* root, node*& head) {
    if (root == NULL) return;

    // Process right subtree first
    convertIntoSortedLL(root->right, head);

    // Link current node with head
    root->right = head;
    if (head != NULL) {
        head->left = root;
    }

    // Move head to current node
    head = root;

    // Process left subtree
    convertIntoSortedLL(root->left, head);
}



// void convertIntoSortedLL(node* root, node*& head) {
//     if (root == NULL) return;

//     // Step 1: Process left subtree
//     convertIntoSortedLL(root->left, head);

//     // Step 2: Link current node with head
//     root->right = head;
//     if (head != NULL) {
//         head->left = root;
//     }

//     // Move head to current node
//     head = root;

//     // Step 3: Process right subtree
//     convertIntoSortedLL(root->right, head);
// }



// STEP 2 merge two sorted linked list
node* mergeLL(node* head1, node* head2){
    node* head = NULL;
    node* tail = NULL;

    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if(head == NULL){
                head  = head1;
                tail = head1;
                head1 = head1->right;
            }else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{
            if(head == NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while(head1 != NULL){
        tail->right = head1;
        head1 -> left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while(head2 != NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;

    }

    return head;
}

//   STEP 3 --merged sorted linkedlist into binary search tree

int countnodes(node* head){
    int count = 0;
    node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->right;
    }

    return count;
}

node* sortedLLtoBST(node* &head, int n){

    if(n <=0 || head == NULL){
        return NULL;
    }

    node* left = sortedLLtoBST(head,n/2);

    node* root = head;
    root->left = left;
    head = head->right;

    root->right = sortedLLtoBST(head,n-n/2-1);

    return root;
}

int main(){

    node* root1 = NULL;
    node* head1 = NULL;
    node* root2 = NULL;
    node* head2 = NULL;

    cout << "ENTER THE DATA FOR BST";
    root1 = takeinput(root1);

    cout << "ENTER THE DATA FOR BST";
    root2 = takeinput(root2);

    convertIntoSortedLL(root1,head1);
    convertIntoSortedLL(root2,head2);
    node* mergedHead = mergeLL(head1, head2);
    int n = countnodes(mergedHead);
    node* finalBST = sortedLLtoBST(mergedHead, n);
    traversal(finalBST);

}