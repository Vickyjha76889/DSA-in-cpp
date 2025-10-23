#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

node* mergeKSortedLL(vector<node*> linkedlist,int k){
    priority_queue<node*,vector<node*>,compare> minheap;

    // step 1 : store all first elements of all linkes list
    for(int i = 0;i<k;i++){
        if(linkedlist[i] != NULL){
            minheap.push(linkedlist[i]);
        }
    }

    node* head = NULL;
    node* tail = NULL;

    while(!minheap.empty()){
        node* tmp = minheap.top();
        minheap.pop();

        if(tmp->next != NULL){
                minheap.push(tmp->next);
            }

        if(head == NULL){
            head = tail = tmp;
            tail->next = NULL;
        }
        else{

            tail->next = tmp;
            tail = tmp;
            tail->next = NULL;

        }
    }

    return head;
}

// Helper function to print linked list
void printList(node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create linked list from vector
node* createList(vector<int> arr) {
    if (arr.size() == 0) return NULL;
    node* head = new node(arr[0]);
    node* tail = head; 
    for (int i = 1; i < arr.size(); i++) {
        tail->next = new node(arr[i]);
        tail = tail->next;
    }
    return head;
}

// Main function
int main() {
    // Example: 3 sorted linked lists
    vector<int> v1 = {1, 4, 7};
    vector<int> v2 = {2, 5, 8};
    vector<int> v3 = {3, 6, 9};

    node* l1 = createList(v1);
    node* l2 = createList(v2);
    node* l3 = createList(v3);

    vector<node*> lists = {l1, l2, l3};

    node* mergedHead = mergeKSortedLL(lists, lists.size());

    cout << "Merged Linked List: ";
    printList(mergedHead);

    return 0;
}