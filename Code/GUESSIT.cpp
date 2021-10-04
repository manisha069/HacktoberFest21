// Solution to https://www.codechef.com/COOK127C/problems/GUESSIT

#include <bits/stdc++.h>

#define get cin>> 
#define print cout<<
#define f(s,n) for(int i = s; i < n; i++)
#define inarr(s,n,arr) for (int i = s; i < n; i++) cin>>arr[i];
#define outarr(s,n,arr) for (int i = s; i < n; i++) cout<<arr[i];
#define ll long long
using namespace std;

int code(){
    int ll n=0, check=0, count=1;

    while(n == 0){
        print count * count<<endl;
        cout.flush();
        get n;
        
        if(n==1 || count > 2000){
            break;
        }
        else{
            count++;
        }
        cout.flush();
    }
    return 0;
}

int main() {
    int t;
    get t;
    while(t>0){
        code();
        t--;
    }
    return 0;
}