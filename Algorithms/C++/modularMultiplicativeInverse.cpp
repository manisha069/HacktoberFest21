/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
#include <bits/stdc++.h>
using namespace std;

#define llint long long

// this algorithm uses extended euclidean as it's base and calculates
// modular multiplicative inverse of 'a' under mod 'b';

//MODULAR MULTIPLICATIVE INVERSE
//(i)  Extended Euclidean Algorithm
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
//(ii) Modular Multiplicative Inverse
//returns modular multiplicative inverse of 'a' under mod 'b';
llint modInv(llint a, llint b){
    llint x,y;
    gcdExt(a,b,x,y);
    return x%b;
}
//NOTE:- makes sense iff gcd(a,b)==1;

int main(){
    llint a,b,x,y;
    cin>>a>>b;
    cout<<a<<" * "<<modInv(a,b)<<" = 1 (mod "<<b<<")\n";
    return 0;
}
/*
    |---------------------------------------------------|
    |||   https://codeforces.com/profile/codechaser   |||
    |||   https://www.codechef.com/users/codechaser   |||
    |||        https://github.com/code-chaser         |||
    |---------------------------------------------------|
*/