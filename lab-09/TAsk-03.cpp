#include <iostream>
using namespace std;

struct Node{
    int key, height;
    Node *left, *right;
    Node(int k): key(k), height(1), left(NULL), right(NULL){}
};

int height(Node* n){ return n ? n->height : 0; }
int bal(Node* n){ return n ? height(n->left)-height(n->right) : 0; }

Node* rightRot(Node* y){
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    y->height = max(height(y->left),height(y->right))+1;
    x->height = max(height(x->left),height(x->right))+1;
    return x;
}

Node* leftRot(Node* x){
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = max(height(x->left),height(x->right))+1;
    y->height = max(height(y->left),height(y->right))+1;
    return y;
}

Node* insert(Node* root, int k){
    if(!root) return new Node(k);
    if(k < root->key) root->left = insert(root->left,k);
    else root->right = insert(root->right,k);

    root->height = max(height(root->left),height(root->right))+1;

    int b = bal(root);
    if(b > 1 && k < root->left->key) return rightRot(root);
    if(b < -1 && k > root->right->key) return leftRot(root);
    if(b > 1 && k > root->left->key){
        root->left = leftRot(root->left);
        return rightRot(root);
    }
    if(b < -1 && k < root->right->key){
        root->right = rightRot(root->right);
        return leftRot(root);
    }
    return root;
}

void pre(Node* r){
    if(!r) return;
    cout << r->key << " ";
    pre(r->left);
    pre(r->right);
}

int main(){
    Node* root = NULL;
    int a[] = {10,5,15,3,7};
    for(int x : a) root = insert(root,x);

    root = insert(root,12);

    pre(root);
}

