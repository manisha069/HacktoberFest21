#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums)
{
    int n = nums.size();

    int pre = 0, flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > pre)
        {
            flag = 1;
            break;
        }
        pre = max(pre, i + nums[i]);
    }

    if (flag == 1)
    {
        return false;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;

    vector<int> jump(n);
    for(int i=0; i<n; i++)
    {
        cin>>jump[i];
    }

    bool ans = canJump(jump);
    cout<<ans<<endl;
    return 0;
}