#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define asc(i,x,n) for(I i=x;i<n;i++)
#define dsc(i,x,n) for(I i=x;i>=n;i--)
#define W(t) int t;cin>>t;while(t--)
#define U unsigned
#define I long long int
#define S string
#define C char
#define D long double
#define A auto
#define B bool
#define pb push_back
#define V(x) vector<x>
#define mod 1000000007
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
list<int> l1;
l1.push_back(5);
l1.push_back(6);

auto it=l1.begin();
cout<<*it<<endl;

return 0;
}