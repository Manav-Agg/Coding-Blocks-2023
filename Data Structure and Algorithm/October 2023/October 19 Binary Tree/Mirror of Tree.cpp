#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left, *right;

    node(int d){
        data = d;
        left = right = NULL;
    }
};

node* buildTree(){
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    node* root = new node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void printLevelOrder(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        q.pop();

        if(f != NULL){
            cout << f->data << " ";
            
            if(f->left){
                q.push(f->left);
            }

            if(f->right){
                q.push(f->right);
            }
        }
        else{
            cout << endl;

            if(!q.empty()){
                q.push(NULL);
            }
        }
    }
}

void mirror(node* root){
    if(!root){
        return;
    }

    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

int main(){
    // input: 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    node* root = buildTree();
    printLevelOrder(root);
    mirror(root);
    printLevelOrder(root);
}