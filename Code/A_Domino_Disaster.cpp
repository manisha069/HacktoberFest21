#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define fo(i,a,b) for(int i=a ; i<b ; i++)
#define foe(i,a,b) for(int i=a ; i<=b ; i++)
#define endl '\n'
#define ff first
#define ss second
#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll t;
     cin>>t;
    // t=1;
    while(t--)
    {
        ll n;
        cin>>n;
        string s,p;
        cin>>s;
        for(ll i=0;i<s.size();i++)
        {
            if(s[i]=='D')
            s[i]='U';
            else if (s[i]=='U')
            s[i]='D';
        }
    cout<<s<<endl;

    }
    
    return 0;
}


