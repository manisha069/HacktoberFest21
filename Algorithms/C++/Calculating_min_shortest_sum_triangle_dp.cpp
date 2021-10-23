#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;
typedef long long unsigned llu;

class Solution
{
public:
    long minimumTotal(vector<vector<long>> &t)
    {

        long m = t.size();
        long n = t[m - 1].size();
        long ntemp = n - 1;

        for (long i = m - 2; i >= 0; i--)
        {
            for (long j = 0; j < ntemp; j++)
                t[i][j] += min(t[i + 1][j], t[i + 1][j + 1]);
        
            ntemp--;
        }

        return t[0][0];
    }
};

int main()
{
    Solution obj1;
    vector<vector<long>> vec{{1, 2}, {1, 2, 3}, {6, 5, 8, 9}, {4, 6, 1, 0}};

    cout << obj1.minimumTotal(vec) << endl;

    return 0;
}