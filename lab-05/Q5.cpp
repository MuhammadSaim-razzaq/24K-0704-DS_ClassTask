#include<iostream>
using namespace std;

int sum(int n){
    if(n == 0){
        return 0;
    }
    else{
        return n%10 + sum(n/10);
    }
}

int main(){
    int number;
    cout<<"Enter Number:";
    cin>>number;
    cout<<"sum :";
    cout<<sum(number);
}
