#include <bits/stdc++.h>
using namespace std;

string decimal_to_binary(int n)
{
   string ans;
   while(n>0){
       int current_bit = n&1;
       ans+=current_bit+'0';
       n>>=1;
   }
   reverse(ans.begin(),ans.end());
   return ans;
}
int main()
{
    string binary = decimal_to_binary(244);
    cout << binary << endl;
    return 0;
}
