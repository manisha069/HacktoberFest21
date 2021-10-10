#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;

    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    int t=0,l=0,d=n-1,r=m-1,dir=0;
    while(t<=d and l<=r){
        if(dir==0){
            for(int i=l;i<=r;i++){
                cout<<arr[t][i]<<" ";
            }
            t++;
        }
        if(dir==1){
            for(int i=t;i<=d;i++){
                cout<<arr[i][r]<<" ";
            }
            r--;
        }
        if(dir==2){
            for(int i=r;i>=l;i--){
                cout<<arr[d][i]<<" ";
            }
            d--;
        }
        if(dir==3){
            for(int i=d;i>=t;i--){
                cout<<arr[i][l]<<" ";
            }
            l++;
        }
        dir=(dir+1)%4;
    }
    
}
