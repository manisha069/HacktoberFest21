#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define sum(v) accumulate(v.begin(),v.end(),0)
#define sort(v) sort(v.begin(),v.end())
#define rsort(v) reverse(v.begin(),v.end())
#define mseti multiset<int>
#define vi vector<int>
#define pb push_back
#define fo(i,o,n) for (int i = o; i < n; i++)
#define tc   \
   int t;    \
   cin >> t; \
   while(t--)
#define i(n) \
   int n;    \
   cin >> n;
#define printn(x) cout << x << endl
#define prints(x) cout << x << " "
#define print(x) cout << x

signed main ()
{
   string s; cin>>s;
   vi idx;
   for(int i=0;i<s.size();) {
      string a=s.substr(i,3);
      if (a == "WUB") {
         i=i+3;
         continue;
      }
      else {
         idx.pb(i);
         i++;
      }
   }
   print(s[idx[0]]);
   fo(i,1,idx.size()) {
      if (idx[i-1]==idx[i]-1)
         print(s[idx[i]]);
      else
         cout << " " << s[idx[i]];
   }
}