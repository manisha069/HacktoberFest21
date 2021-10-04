#include <bits/stdc++.h>
using namespace std;
  void nextPermutation(vector<int>& nums) {
        int i=0,j=0,n=nums.size(),pos1=-1,pos2=0;
        for(i=n-1;i>=1;i--)
        {
            if(nums[i]>nums[i-1])
            {
                pos1=i-1;
                break;
            }
        }
        if(pos1==-1)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            for(j=n-1;j>=0;j--)
           {
            if(nums[j]>nums[pos1])
            {
                pos2=j;
                break;
            }
          }
             swap(nums[pos1],nums[pos2]);
             reverse(nums.begin()+pos1+1,nums.end()); 
        }
        
    }
    int main()
    {
        int n,i;
        cin>>n;
        vector<int>v(n);
        for(i=0;i<n;i++)
        cin>>v[i];
        nextPermutation(v);
        for(i=0;i<n;i++)
        cout<<v[i]<<" ";
    }