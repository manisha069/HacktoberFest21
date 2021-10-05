#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
const int N = 1e2;
const int MOD = 1e9 + 7;
vi adj[51];
vector<ll> sol(51, 0);
//cout << fixed << setprecision(10);
//sorting
/* int n = sizeof(arr) / sizeof(arr[0]);
     sort(arr, arr + n);*/
//__gcd(m, n)
void dfs(vi &vis, int x, ll answer, vi &gold, int p)
{
    // preorder
    vis[x] = 1;
    //inorder
    vi ::iterator it;
    int count = 0;
    for (it = adj[x].begin(); it != adj[x].end(); it++)
    {
        if (vis[*it] == 0)
        {
            count++;
            answer += gold[*it];
            if (x == 1)
                dfs(vis, *it, answer, gold, *it);
            else
                dfs(vis, *it, answer, gold, p);
            answer -= gold[*it];
        }
    }

    if (count == 0)
    {
        sol[p] = max(sol[p], answer);
        //cout << answer << " ";
    }
    //postorder
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int qi = 0; qi < t; qi++)
    {

        int n;
        cin >> n;
        vi gold(n + 1);
        vi vis(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> gold[i];
        }
        int x, y;
        for (int i = 1; i <= n - 1; i++)
        {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(vis, 1, 0, gold, 0);
        ll max1 = 0, max2 = 0;
        for (int i = 1; i < 51; i++)
        {
            //cout << i;
            if (max1 <= sol[i])
            {
                max2 = max1;
                max1 = sol[i];
            }
            else if (max2 <= sol[i])
                max2 = sol[i];
        }
        ll sol1 = max2 + max1 + gold[1];
        cout << "Case #" << qi + 1 << ": " << sol1 << "\n";
        for (int i = 0; i < 51; i++)
        {
            adj[i].clear();
        }
        for (int i = 0; i < 51; i++)
        {
            sol[i] = 0;
        }
    }
    return 0;
}