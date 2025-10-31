#include <bits/stdc++.h>
using namespace std;

struct Node{
    int id;
    int qty;
    Node *left,*right;
    Node(int i,int q):id(i),qty(q),left(nullptr),right(nullptr){}
};

Node* insertOrUpdate(Node* root,int id,int qty){
    if(!root) return new Node(id, qty);
    if(id < root->id) root->left = insertOrUpdate(root->left, id, qty);
    else if(id > root->id) root->right = insertOrUpdate(root->right, id, qty);
    else root->qty = qty;
    return root;
}

Node* search(Node* root,int id){
    if(!root) return nullptr;
    if(id==root->id) return root;
    if(id < root->id) return search(root->left,id);
    return search(root->right,id);
}

void findMaxQty(Node* root, Node*& best){
    if(!root) return;
    if(!best || root->qty > best->qty) best = root;
    findMaxQty(root->left, best);
    findMaxQty(root->right, best);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Node* root = nullptr;
    int ops;
    if(!(cin>>ops)) return 0;
    while(ops--){
        int t;
        cin>>t;
        if(t==1){
            int id, qty;
            cin>>id>>qty;
            root = insertOrUpdate(root, id, qty);
        } else if(t==2){
            int id;
            cin>>id;
            Node* r = search(root, id);
            if(r) cout<<r->id<<" "<<r->qty<<"\n";
            else cout<<"Not Found\n";
        } else if(t==3){
            Node* best = nullptr;
            findMaxQty(root, best);
            if(best) cout<<best->id<<" "<<best->qty<<"\n";
            else cout<<"Tree Empty\n";
        }
    }
    return 0;
}
