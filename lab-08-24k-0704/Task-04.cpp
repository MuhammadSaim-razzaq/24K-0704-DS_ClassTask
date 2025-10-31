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
    for(int i=0;i<n;i++) nodes[i] = new Node(a[i]);
    for(int i=0;i<n;i++){
        int l=2*i+1, r=2*i+2;
        if(l<n) nodes[i]->left = nodes[l];
        if(r<n) nodes[i]->right = nodes[r];
    }
    return nodes[0];
}

bool found = false;
Node* foundNode = nullptr;

int subtreeSum(Node* r, int target){
    if(!r) return 0;
    int s = r->val + subtreeSum(r->left, target) + subtreeSum(r->right, target);
    if(s==target && !found){
        found = true;
        foundNode = r;
    }
    return s;
}

void printPreorder(Node* r){
    if(!r) return;
    cout<<r->val<<" ";
    printPreorder(r->left);
    printPreorder(r->right);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Node* root = buildFromLevelOrder();
    int target;
    if(!(cin>>target)) return 0;
    subtreeSum(root, target);
    if(found){
        printPreorder(foundNode);
        cout<<"\n";
    } else {
        cout<<"No subtree with given sum\n";
    }
    return 0;
}
