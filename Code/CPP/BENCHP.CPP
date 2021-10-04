// Solution to https://www.codechef.com/problems/BENCHP

#include <bits/stdc++.h>

#define get cin >>
#define print cout <<
#define ll long long
#define ld long double
#define rep(i, k, n) for (ll int i = k; i < n; i++)
#define rept(i, k, n) for (auto i = k; i != n; ++i)
#define drep(i, k, n) for (ll int i = k; i >= n; i--)
#define fi(s, n) for (ll int i = s; i < n; i++)
#define fj(s, n) for (ll int j = s; j < n; j++)
#define fk(s, n) for (ll int k = s; k < n; k++)
#define inarr(s, n, arr)           \
    for (ll int i = s; i < n; i++) \
        cin >> arr[i];
#define outarr(s, n, arr)          \
    for (ll int i = s; i < n; i++) \
        cout << arr[i] << ' ';
using namespace std;

int code()
{

    ll int n, w, wr;
    get n >> w >> wr;

    map<int, int> map;
    ll int arr[n];

    fi(0, n)
    {
        get arr[i];
        map[arr[i]]++;
    }

    if (wr >= w)
        print "YES\n";

    else
    {
        w = w - wr;

        fi(0, n)
        {

            if (map[arr[i]] >= 2)
            {
                ll int count = map[arr[i]];

                if (count % 2 == 0)
                {
                    w -= count * arr[i];
                }
                else
                {
                    w -= (count - 1) * arr[i];
                }
                map[arr[i]] = 0;
            }
            if (w <= 0)
                break;
        }
        if (w <= 0)
            print "YES\n";
        else
            print "NO\n";
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    get t;
    while (t > 0)
    {
        code();
        t--;
    }
    return 0;
}