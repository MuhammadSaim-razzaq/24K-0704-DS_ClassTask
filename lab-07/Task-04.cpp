#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* newNode(int x){
    Node* t=new Node;
    t->data=x;
    t->next=NULL;
    return t;
}

Node* getTail(Node* cur){
    while(cur && cur->next) cur=cur->next;
    return cur;
}

Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd){
    Node* pivot=end;
    Node* prev=NULL,*cur=head,*tail=pivot;

    while(cur!=pivot){
        if(cur->data < pivot->data){
            if(!(*newHead)) *newHead=cur;
            prev=cur;
            cur=cur->next;
        }
        else{
            if(prev) prev->next=cur->next;
            Node* tmp=cur->next;
            cur->next=NULL;
            tail->next=cur;
            tail=cur;
            cur=tmp;
        }
    }
    if(!(*newHead)) *newHead=pivot;
    *newEnd=tail;
    return pivot;
}

Node* quickSortRecur(Node* head, Node* end){
    if(!head || head==end) return head;
    Node *newHead=NULL,*newEnd=NULL;
    Node* pivot=partition(head,end,&newHead,&newEnd);
    if(newHead!=pivot){
        Node* tmp=newHead;
        while(tmp->next!=pivot) tmp=tmp->next;
        tmp->next=NULL;
        newHead=quickSortRecur(newHead,tmp);
        tmp=getTail(newHead);
        tmp->next=pivot;
    }
    pivot->next=quickSortRecur(pivot->next,newEnd);
    return newHead;
}

void quickSort(Node** head){
    *head=quickSortRecur(*head,getTail(*head));
}

int main(){
    int arr[]={10,7,8,9,1,5,3};
    Node* head=NULL;
    for(int i=0;i<7;i++){
        Node* t=newNode(arr[i]);
        t->next=head;
        head=t;
    }
    quickSort(&head);
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}
