// Solution to https://www.codechef.com/MARCH21C/problems/SPACEARR

#include <bits/stdc++.h>

#define get cin>> 
#define print cout<<
#define f(s,n) for(int i = s; i < n; i++) 
#define inarr(s,n,arr) for (int i = s; i < n; i++) cin>>arr[i];
#define outarr(s,n,arr) for (int i = s; i < n; i++) cout<<arr[i];
using namespace std;

int code(){

    int n;
    get n;
    int a[n];

    inarr(0,n,a);

    int x = sizeof(a) / sizeof(a[0]);
    sort(a, a + x); 

    int ans=0, c=0;
    f(0,n){
        int temp = i+1 - a[i];
        if(temp < 0){
            c = 1;
            break;
        }
        ans = ans + temp;
    }

    if(c ==1) print "Second";
    else {
        if(ans % 2 == 1) print "First";
        else print "Second";
    }
    print "\n";

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