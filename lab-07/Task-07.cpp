#include <bits/stdc++.h>
using namespace std;

int getMax(vector<int> &a){
    int m=a[0];
    for(int i=1;i<a.size();i++)
        if(a[i]>m) m=a[i];
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
    for(int exp=1;mx/exp>0;exp*=10)
        countingSort(a,exp);
}

int main(){
    vector<int> scores = {
        55,72,91,43,67,89,12,100,34,76,
        58,60,49,85,95,10,27,19,88,99,
        63,45,50,79,90,44,57,81,92,33,
        25,18,71,66,40,36,29,77,82,59,
        83,97,22,30,70,65,46,52,61,74
    };

    radixSort(scores);

    cout<<"Score   Rank\n";
    for(int i=0;i<scores.size();i++){
        cout<<scores[i]<<"     "<<i+1<<"\n";
    }
}
