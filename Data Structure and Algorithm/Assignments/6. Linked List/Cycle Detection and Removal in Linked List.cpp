#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    
    Node(int d){
        data = d;
        next = NULL;
    }
};

void breakCycle(Node* head, Node* slow){
    Node* meet = slow;
    Node* start = head;
    Node* pre = head;
    
    while(start != meet){
        meet = meet -> next;
        start = start -> next;
    }
    
    while(pre->next != meet){
        pre = pre-> next;
    }
    pre -> next = NULL;
}

bool floydCycleRemoval(Node* head){
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        
        if(slow == fast){
            breakCycle(head, slow);
            return true;
        }
    }
    return false;
}

void buildCycleList(Node *&head){
    unordered_map<int, Node*> hash;
    int x;
    cin >> x;

    if(x == -1){
        head = NULL;
        return;
    }

    head = new Node(x);
    hash[x] = head;
    Node *current = head;
    
    while(x != -1){
        cin >> x;
        if(x == -1){
            break;
        }
        
        if(hash.find(x) != hash.end()){
            current->next = hash[x];
            return;
        }

        Node *n = new Node(x);
        current->next = n;
        current = n;
        hash[x] = n;
    }
    current->next = NULL;
}

void printLinkedList(Node *head){
    unordered_set<int> s;
    while(head != NULL){
        if(s.find(head->data) != s.end()){
            cout << "\nCycle detected at " << head->data;
            return;
        }

        cout << head->data << " ";
        s.insert(head->data);
        head = head->next;
    }
}

int main(){
    Node *head = NULL;
    buildCycleList(head);
    bool cyclePresent = floydCycleRemoval(head);
    
    if(cyclePresent){
        cout << "Cycle was present\n";
    }
    else{
        cout << "No cycle\n";
    }

    cout << "Linked List - ";
    printLinkedList(head);
}