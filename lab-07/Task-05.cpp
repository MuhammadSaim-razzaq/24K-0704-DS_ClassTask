#include <bits/stdc++.h>
using namespace std;

int cnt;
int partitionF(vector<int> &a,int l,int r){
    cnt++;
    int p=a[l],i=l;
    for(int j=l+1;j<=r;j++){
        cnt++;
        if(a[j]<p) swap(a[++i],a[j]);
    }
    swap(a[l],a[i]);
    return i;
}
int partitionM(vector<int> &a,int l,int r){
    int mid=(l+r)/2;
    swap(a[l],a[mid]);
    return partitionF(a,l,r);
}
int partitionR(vector<int> &a,int l,int r){
    int x=l+rand()%(r-l+1);
    swap(a[l],a[x]);
    return partitionF(a,l,r);
}
int partitionMT(vector<int> &a,int l,int r){
    int m=(l+r)/2;
    int x=l;
    if((a[l]<=a[m] && a[m]<=a[r])||(a[r]<=a[m] && a[m]<=a[l])) x=m;
    else if((a[m]<=a[r] && a[r]<=a[l])||(a[l]<=a[r] && a[r]<=a[m])) x=r;
    swap(a[l],a[x]);
    return partitionF(a,l,r);
}
void QS(vector<int> &a,int l,int r,int type){
    if(l>=r) return;
    int p=(type==1?partitionF(a,l,r):type==2?partitionR(a,l,r):type==3?partitionM(a,l,r):partitionMT(a,l,r));
    QS(a,l,p-1,type);
    QS(a,p+1,r,type);
}

int main(){
    vector<int> arr = {10,7,8,9,1,5,3};
    
    vector<int> a;
    
    a=arr; cnt=0; QS(a,0,a.size()-1,1); cout<<"First Pivot: "<<cnt<<"\n";
    a=arr; cnt=0; QS(a,0,a.size()-1,2); cout<<"Random Pivot: "<<cnt<<"\n";
    a=arr; cnt=0; QS(a,0,a.size()-1,3); cout<<"Middle Pivot: "<<cnt<<"\n";
    a=arr; cnt=0; QS(a,0,a.size()-1,4); cout<<"Median-of-Three Pivot: "<<cnt<<"\n";
}
