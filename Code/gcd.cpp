#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,m;
cin>>n>>m;

while(m!=0)
{
    int rem=n%m;
    n=m;
    m=rem;

}

cout<<n;
return 0;
}
