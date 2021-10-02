#include<bits/stdc++.h>
using namespace std;
int check(int n, int k)
    {
       if (n & (1 << (k - 1))) 
		return true; 
	else
		return false; 
    }

 int main()
 {
     int n,m,k=1;
     cin>>n>>m;
     int x=32;
     while(x>0)
     {
         if(check(n,k)!=check(m,k))
         {
             break;
         }
         else
         {k++;}
     }
     cout<<k;
 }   