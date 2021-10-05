#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
const int N = 500;
const int MOD = 1e9 + 7;
vector<char> adj[N + 1];

void traverse(vi &st, vvi &ans, int parent, int src, int count)
{
    st[src]++;
    if (parent != src)
    {
        if (ans[parent][src] != -1)
            ans[parent][src] = min(ans[parent][src], count);
        else
            ans[parent][src] = count;
        if (st[src] == 2)
            return;
        for (auto i : adj[src])
        {
            if ((i - 'A' + 1) != parent)
            {
                traverse(st, ans, parent, i - 'A' + 1, count + 1);
            }
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int qi = 0; qi < t; qi++)
    {
        vi distinct(27, 0);
        vvi ans(27, vi(27, -1));
        int k;
        string s;
        cin >> s >> k;
        for (int i = 1; i <= k; i++)
        {
            char x, y;
            cin >> x >> y;
            adj[x - 'A' + 1].push_back(y);
        }
        for (int i = 0; i < s.size(); i++)
        {
            distinct[s[i] - 'A' + 1]++;
        }
        int min_idx = INT_MAX;
        for (int i = 1; i <= 26; i++)
        {
            if (min_idx > distinct[i])
            {
                min_idx = distinct[i];
            }
        }
        if (min_idx == s.size())
        {
            cout << "Case #" << qi + 1 << ": 0\n";
            continue;
        }
        for (int i = 1; i <= 26; i++)
        {
            ans[i][i] = 0;
            for (auto q : adj[i])
            {
                vi st(27, 0);
                if ((q - 'A' + 1) != i)
                {

                    traverse(st, ans, i, q - 'A' + 1, 1);
                }
            }
        }

        // for (int j = 0; j < 27; j++)
        // {
        //     for (auto i : adj[j])
        //     {
        //         if (i != j)
        //         {
        //             cout << j << " -> " << i;
        //         }
        //     }
        // }
        int min_ans = INT_MAX;
        for (int i = 1; i <= 26; i++)
        {
            int flag = 0, answer = 0;
            for (int j = 0; j < s.size(); j++)
            {
                if (ans[s[j] - 'A' + 1][i] != -1)
                {
                    answer += ans[s[j] - 'A' + 1][i];
                }
                else
                {
                    // cout << s[j] - 'A' + 1 << "," << i;
                    flag = 1;
                    break;
                }
            }

            if (flag == 1)
                continue;
            else
            {
                // cout << i << " " << answer << "\n";
                min_ans = min(min_ans, answer);
            }
        }
        if (min_ans == INT_MAX)
            cout << "Case #" << qi + 1 << ": -1\n";
        else
            cout << "Case #" << qi + 1 << ": " << min_ans << "\n";
        for (int i = 0; i < 27; i++)
        {
            adj[i].clear();
        }
    }
    return 0;
}