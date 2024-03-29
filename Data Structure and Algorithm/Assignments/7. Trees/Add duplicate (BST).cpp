#include<iostream>
using namespace std;
class node{ 
    public:
    node* left;
    int data;
    node* right;
    
    node(int x){
        left = NULL;
        data = x;
        right = NULL;
    }
};

node* insertion_in_bst(node* root, int value){
    //base case
    if(root == NULL){
        root = new node(value);
        return root;
    }
    
    //recursive case
    if(value < root->data){
        root->left = insertion_in_bst(root->left, value);
    }

    else{
        root->right = insertion_in_bst(root->right, value);
    }
    return root;
}

void duplicate(node* root){
    // Base Case:
    if(root == NULL){
        return;
    }

    // recursive Case:
    /// our work is to duplicate the current node and place it on left
    node* temp = root->left;
    root->left = new node(root->data);
    root->left->left = temp;

    // now call for left and right
    if(root->left->left){
        duplicate(root->left->left);
    }
    duplicate(root->right);
}

void print(node* root){
    //base
    if(root == NULL){
        return;
    }
    
    if(root->left != NULL){
        cout << root->left->data;
    }
    else{
        cout << "END";
    }

    cout << " => ";
    cout << root->data;
    cout << " <= ";
    
    if(root->right != NULL){
        cout << root->right->data;
    }
    else{
        cout << "END";
    }

    cout << endl;
    print(root->left);
    print(root->right);
}

int main(){
    node* root = NULL;
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        int data;
        cin >> data;
        root = insertion_in_bst(root,data);
    }

    duplicate(root);
    print(root);
}