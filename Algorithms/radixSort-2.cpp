/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
#include <bits/stdc++.h>
using namespace std;
//OPTIMIZATION
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#define rep0(i,k,n) for(llint i=k;i<n;i++)
#define rep1(i,k,n) for(llint i=k;i>n;i--)
#define rep2(i,k,n,a) for(llint i=k;(i<n)&&(a);i++)
#define br cout<<"\n";
#define print0(x) for(auto i:x) cout<<i<<" "; br;
#define print1(x) for(auto i:x) cout<<i.first<<" "<<i.second<<"\n"; br;
#define pb push_back
#define mp make_pair
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define fileinput freopen("input.txt","r",stdin);
#define fileoutput freopen("output.txt","w",stdout);
//#define a(i,j,n) a[i][j]
//#define a(i,j,n) a[i*n+j]
typedef long long llint;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<llint> vl;
typedef pair<llint,llint> pll;
typedef pair<llint,string> pls;
typedef map<llint,llint> mll;
uint uintMax=4294967295;         //+(1<<32) - 1
int intMax=2147483647;           //+(1<<31) - 1
int intMin=-2147483648;          //-(1<<31)
ull ullMax=18446744073709551615; //+(1<<64) - 1
llint Max=9223372036854775807;   //+(1<<63) - 1
llint Min=-9223372036854775808;  //-(1<<63)

////////////////////////////////////////////////////////////////////////////////////////////////////////////
llint digits(llint n){
    if(n<0) n*=(-1);
    llint i=0;
    while(n) i++,n/=10;
    return i;
}
void rsort(vector<llint>& v){
    llint n=v.size(),max=v[0];
    rep0(i,1,n) if(v[i]>max) max=v[i];
    rep0(i,0,digits(max)){
        vector<vector<llint>> record(10);
        rep0(j,0,n) (record[(llint)abs((llint)((v[j])%((llint)pow(10,i+1)))/pow(10,i))]).pb(v[j]);
        llint counter=0;
        rep0(j,0,10) for(auto k:record[j]) v[counter]=k,counter++;
    }
    return;
}

void codechaser(){
    llint n,ans=0;
    cin>>n;
    vector<llint> v(n);
    rep0(i,0,n) cin>>v[i];
    rsort(v);
    print0(v);
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    llint t=1;
    cin>>t;
    while(t--) codechaser();
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////