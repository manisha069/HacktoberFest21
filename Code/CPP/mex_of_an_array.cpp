#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i;
    cin>>n;
    int a[n];
    map<int,int> mapp;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        mapp[a[i]]++;
    }
    for(i=0;i<n+1;i++){
        if(mapp[i]==0){
            cout<<i<<endl;
            return 0;
        }
    }
}