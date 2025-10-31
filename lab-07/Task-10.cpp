#include <bits/stdc++.h>
using namespace std;

int getMax(vector<int> &a){
    int m=a[0];
    for(int i=1;i<a.size();i++) if(a[i]>m) m=a[i];
    return m;
}

void countingSort(vector<int> &a,int exp){
    int n=a.size();
    vector<int> out(n), cnt(10,0);
    for(int i=0;i<n;i++) cnt[(a[i]/exp)%10]++;
    for(int i=1;i<10;i++) cnt[i]+=cnt[i-1];
    for(int i=n-1;i>=0;i--){
        int d=(a[i]/exp)%10;
        out[cnt[d]-1]=a[i];
        cnt[d]--;
    }
    a=out;
}

void radixSort(vector<int> &a){
    int mx=getMax(a);
    for(int exp=1;mx/exp>0;exp*=10){
        countingSort(a,exp);
    }
}

int main(){
    vector<int> a(20);
    for(int i=0;i<20;i++) cin>>a[i];
    cout<<"Before: ";
    for(int x:a) cout<<x<<" ";
    cout<<"\n";
    radixSort(a);
    cout<<"After: ";
    for(int x:a) cout<<x<<" ";
    return 0;
}
