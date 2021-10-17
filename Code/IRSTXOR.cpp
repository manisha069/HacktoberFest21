// Solution to https://www.codechef.com/MARCH21C/problems/IRSTXOR

#include <bits/stdc++.h>

#define get cin >>
#define print cout <<
#define f(i,s,n)(int i = s; i < n; i++)
#define inarr(i,s,n,arr) for (int i = s; i < n; i++) cin>>arr[i];
#define outarr(i,s,n,arr) for (int i = s; i < n; i++) cout<<arr[i];
using namespace std;

int code(){
    long int n;
    get n;
    long long int tot=0, x=1;
    while(n>=tot){
        tot = pow(2,x);
        x++;
        }
        
    long long int l,m,sum;
    l = pow(2,(x-2));
    m = tot-n;
    sum = (l-1) * ((l-1) + m);
    print sum << "\n";
    return 0;
}

int main() {
    long long int t;
    get t;
    while(t>0){
        code();
        t--;
    }
    return 0;
}