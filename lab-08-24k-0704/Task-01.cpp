#include <bits/stdc++.h>
using namespace std;

struct Node{
    string name;
    Node *left, *right;
    Node(string v):name(v),left(nullptr),right(nullptr){}
};

Node* buildFromLevelOrder(){
    int n;
    if(!(cin>>n)) return nullptr;
    if(n<=0) return nullptr;
    vector<string> vals(n);
    for(int i=0;i<n;i++) cin.ignore(n?0:0), getline(cin, vals[i]);
    vector<Node*> nodes(n,nullptr);
    for(int i=0;i<n;i++){
        if(vals[i] != "NULL") nodes[i] = new Node(vals[i]);
    }
    for(int i=0;i<n;i++){
        if(!nodes[i]) continue;
        int l = 2*i+1, r = 2*i+2;
        if(l<n) nodes[i]->left = nodes[l];
        if(r<n) nodes[i]->right = nodes[r];
    }
    return nodes[0];
}

void printSideways(Node* root,int space=0){
    if(!root) return;
    printSideways(root->right, space+4);
    for(int i=0;i<space;i++) cout<<' ';
    cout<<root->name<<"\n";
    printSideways(root->left, space+4);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    getline(cin, line);
    Node* root = buildFromLevelOrder();
    if(!root) return 0;
    printSideways(root);
    return 0;
}
