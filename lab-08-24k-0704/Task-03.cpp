#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left,*right;
    Node(int v):val(v),left(nullptr),right(nullptr){}
};

Node* buildFromLevelOrder(){
    int n;
    if(!(cin>>n)) return nullptr;
    if(n<=0) return nullptr;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<Node*> nodes(n,nullptr);
    for(int i=0;i<n;i++){
        if(a[i] != -1) nodes[i] = new Node(a[i]);
    }
    for(int i=0;i<n;i++){
        if(!nodes[i]) continue;
        int l=2*i+1,r=2*i+2;
        if(l<n) nodes[i]->left = nodes[l];
        if(r<n) nodes[i]->right = nodes[r];
    }
    return nodes[0];
}

bool isFull(Node* r){
    if(!r) return true;
    if(!r->left && !r->right) return true;
    if(r->left && r->right) return isFull(r->left) && isFull(r->right);
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Node* root = buildFromLevelOrder();
    if(isFull(root)) cout<<"Full Binary Tree\n";
    else cout<<"Not a Full Binary Tree\n";
    return 0;
}
