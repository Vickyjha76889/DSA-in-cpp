
    }

    cout<<endl;

}

void insertatTail(node* &tail , node* curr){

    node* temp = curr;
    tail -> next = temp;
    tail = temp;

}

node* sortLL(node* head){

    node* zerohead = new node(-1);
    node* zerotail = zerohead;

    node* onehead = new node(-1);
    node* onetail = onehead;

    node* twohead = new node(-1);
    node* twotail = twohead;

    node* curr = head;

    while(curr != nullptr){

        int value = curr -> data;

        if(value == 0){

            insertatTail(zerotail,curr);

        }

        else if(value == 1){