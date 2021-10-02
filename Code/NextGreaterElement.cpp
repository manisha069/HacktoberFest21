#include <bits/stdc++.h>
using namespace std;
//Time Complexity O(n)
vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long int>v;
        stack<long long int>s;
        for(int i=n-1;i>=0;i--)
        {
            if(s.size()==0)
            v.push_back(-1);
            
            else if(s.size()>0 && s.top()>arr[i])
            v.push_back(s.top());
            
            else 
            {
                while(s.size()>0 && s.top()<arr[i])
                    s.pop();
                if(s.size()==0)
                v.push_back(-1);
                else 
                v.push_back(s.top());
            }
            s.push(arr[i]);
        }
        reverse(v.begin(),v.end());
        return v;
    }

int main()
{
    int n;
    cin>>n;
    vector<long long int>a(n),res;
    for(int i=0;i<n;i++)
    cin>>a[i];
    res=nextLargerElement(a,n);
    for(int i=0;i<n;i++)
    cout<<res[i]<<" ";
    return 0;
}
