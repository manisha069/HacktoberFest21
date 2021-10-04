#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i;
    cin>>n;
    int mn=INT_MAX,curr=0,a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        curr+=a[i];
        mn=min(mn,curr);
        curr=min(curr,0);
    }

    cout<<mn<<endl;
}