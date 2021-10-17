#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define K 10
#define M 10
#define DIF 2147483648

/* The idea behind sorting negative numbers too is below
-> A signed 32 bit integer goes from -2,147,483,648 to 2,147,483,647
and an unsigned integer from 0 to 4,294,967,295.
-> So you could just add 2,147,483,648 to the signed number to 
convert it to an unsigned one for sorting
then subtract to get back to signed numbers when you have finished sorting*/

void counting_sort(ll arr[], ll  n, ll p) {
    ll element = pow(10, p);
    ll divs = element / 10;
    ll count[M];
    for(ll i = 0; i < M; i++)
        count[i] = 0;
    for(ll i = 0; i < n; i++)
        count[(arr[i] % element) / divs] ++;
    for(ll i = 1; i < M; i++)
        count[i] += count[i-1];
    ll op[n];
    for(ll i = n-1; i >= 0; i--) {
        op[count[(arr[i] % element) / divs] - 1] = arr[i];
        count[(arr[i] % element) / divs] --;
    }
    // copying the array back
    for(ll i = 0; i < n; i++)
        arr[i] = op[i];
}

void radix_sort(ll arr[], ll n) {
    // apply counting sort for all decimal places
    for(ll i = 1; i <= K; i++)
        counting_sort(arr, n, i);
}

int main() {    
    ll n;
    cin >> n;
    ll arr[n];
    // Taking input
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        // Adding DIF to make negative numbers positive
        arr[i]+=DIF;
    }
    // perform the sort
    radix_sort(arr, n);

    // Outputting the sorted array
    for(ll i = 0; i < n; i++) {
        cout << arr[i]-DIF << ' ';
    }
    cout << '\n';
    return 0;
}
