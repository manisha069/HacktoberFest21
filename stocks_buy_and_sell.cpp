
#include <bits/stdc++.h>
using namespace std;



class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> arr, int n){

        vector<vector<int>>v;

        for (int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                v.push_back({i-1,i});

            }

        }
        return v;
    }
};

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{
    int t;
    cout<<"No. of test cases"<<endl;
    cin>>t;
    while(t--){
        int n;
        cout<<"Size of array"<<endl;
        cin>>n;
        cout<<"Elements of array"<<endl;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}
