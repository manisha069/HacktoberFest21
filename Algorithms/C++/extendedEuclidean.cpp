/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
#include <bits/stdc++.h>
using namespace std;

#define llint long long

// this algorithm not only finds GCD of 'a' & 'b', but also calculates
// some integral values of 'x' & 'y' such that the following holds:
//                    a*x + b*y = gcd(a,b)
llint gcdExt(llint a, llint b, llint& x, llint& y){
    if(!a){
        x=0,y=1;
        return b;
    }
    llint x1,y1,g=gcdExt(b%a,a,x1,y1);
    y=x1;
    x=y1-(b/a)*y;
    return g;
}

int main(){
    llint a,b,x,y;
    cin>>a>>b;
    cout<<gcdExt(a,b,x,y)<<" = "<<a<<"*("<<x<<") + "<<b<<"*("<<y<<")\n";
    return 0;
}
/*
    |---------------------------------------------------|
    |||   https://codeforces.com/profile/codechaser   |||
    |||   https://www.codechef.com/users/codechaser   |||
    |||        https://github.com/code-chaser         |||
    |---------------------------------------------------|
*/