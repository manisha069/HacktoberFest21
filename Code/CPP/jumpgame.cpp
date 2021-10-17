#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int last_index = n-1;  //last index to be reached at any time.
    for(int i=n-1 ; i>=0 ; i--) 
    {
        if(i+nums[i] >= last_index)
        {
            last_index = i;
        }
    }
    
    return last_index <= 0;
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
