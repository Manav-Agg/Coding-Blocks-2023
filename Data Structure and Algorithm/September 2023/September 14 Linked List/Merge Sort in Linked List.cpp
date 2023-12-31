#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int d){
        data = d;
        next = NULL;
    }
};

// INSERTION IN LINKED LIST
void insertAtEnd(node* &head, node* &tail, int data){
    if(head == NULL){
        node* n = new node(data);
        head = tail = n;
    }
    else{
        node* n = new node(data);
        tail->next = n;
        tail = n;
    }
}

// MIDDLE OF LINKED LIST
node* midLL(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    node* slow = head;
    node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// MERGE TWO SORTED LINKED LIST
node* mergeLL(node* a, node* b){
    // Base case
    if(!a){
        return b;
    }

    if(!b){
        return a;
    }

    // Recursive case
    node* nH;
    if(a->data < b->data){
        nH = a;
        nH->next = mergeLL(a->next, b);
    }
    else{
        nH = b;
        nH->next = mergeLL(a, b->next);
    }
    return nH;
}

// MERGE SORT IN LINKED LIST
node* mergeSort(node* head){
    // Base case
    if(!head || !head->next){
        return head;
    }

    // Recursive case
    // 1. Divide
    node* mid = midLL(head);
    node* a = head;
    node* b = mid->next;
    mid->next = NULL;

    // 2. Sort
    a = mergeSort(a);
    b = mergeSort(b);

    // 3. Merge
    node* nH = mergeLL(a, b);
    return nH;
}

// PRINTING LINKED LIST
void printLL(node* head){
    while(head != NULL){
        cout << head->data << " --> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main(){
    node* head, *tail;
    head = tail = NULL;
    
    insertAtEnd(head, tail, 4);
    insertAtEnd(head, tail, 3);
    insertAtEnd(head, tail, 5);
    insertAtEnd(head, tail, 2);
    insertAtEnd(head, tail, 6);
    printLL(head);

    node* nH = mergeSort(head);
    printLL(nH);
}