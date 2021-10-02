#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
nCr is the selection of r things from n objects where the order of selection doesen't matter. Its formula is n!/((n-r)!*r!) where k! represents the factorial of a number
*/

int fac[1000001];  //stores factorial of numbers from 1 to 10^6
int rem = 1e9 + 7; //since the result can be very big its mod is taken usin 1e9+7

//function to store the factorial of the first 1e6 numbers
void pre()
{
    fac[0] = 1;
    for (int i = 1; i <= 1e6; i++)
    {
        fac[i] = fac[i - 1] * i;
        fac[i] %= rem;
    }
}
//function to calculate binary exponentiation
int binExp(int x, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2 == 1)
        {
            res *= x;
            res %= rem;
        }
        n /= 2;
        x *= x;
        x %= rem;
    }
    return res;
}
int ncr(int n, int r)
{
    int temp1 = fac[n];
    int temp2 = fac[n - r] * fac[r];
    temp2 %= rem;
    int temp3 = binExp(temp2, rem - 2); // temp3 is the inverse i.e. the denominator of nCr
    temp1 *= temp3;
    temp1 %= rem;
    return temp1;
}

int32_t main()
{
    pre();
    int n, r;
    cin >> n >> r;
    cout << ncr(n, r);
}