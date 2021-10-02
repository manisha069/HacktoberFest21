#include<bits/stdc++.h>
using namespace std;
vector<int>tree;
vector<int>v;
vector<int>lazy;
    void build(int node,int start,int end)
    {
    if(start==end)
    {
        tree[node] = v[start];
    }
    else
    {
        int mid = (start+end)/2;
        build(2*node,start,mid);
        build(2*node + 1,mid+1,end);
        tree[node] = tree[2*node] + tree[2*node + 1];
    }
}
void propagate(int node,int start,int end)
{
    if(start==end){tree[node]+=lazy[node];
    lazy[node]=0;
    }
    else{
    tree[node]+=(end-start+1)*lazy[node];
    lazy[2*node]+=lazy[node];
    lazy[2*node + 1]+=lazy[node];
    lazy[node]=0;
    }
}
void update(int node,int start,int end,int l,int r,int val)
{
    propagate(node,start,end);
    if(end<l || r<start)return;
    if(start==end)
    {
        tree[node]+=val;
    }
    else if(l<=start && end<=r)
    {
        lazy[node]+=val;
        propagate(node,start,end);
    }
    else
    {
        int mid = (start+end)/2;
        update(2*node,start,mid,l,r,val);
        update(2*node + 1,mid+1,end,l,r,val);
        tree[node]=tree[2*node]+tree[2*node +1];
    }
}
int query(int node,int start,int end,int l,int r)
{
    propagate(node,start,end);
    if(end<l || start>r)return 0;
    if(start==end)
    {
        return tree[node];
    }
   else if(start>=l && r>=end)
    {
        return tree[node];
    }
    else
    {
        int mid = (start+end)/2;
        int left = query(2*node,start,mid,l,r);
        int right = query(2*node +1,mid+1,end,l,r);
        return left + right;
    }
}

int main()
{
 
    int n;
    cin >> n;
    v.resize(n);
    tree.resize(4*n);
    lazy.resize(4*n);
    for(auto&it:v)cin >> it;
    build(1,0,n-1);
    int q;
    cin >> q;
    while(q--)
    {
     int a;
     cin >> a;
     if(a)
     {
         int l,r,val;
         cin >> l>>r>>val;
         update(1,0,n-1,l,r,val);
     }
     else
     {
         int l,r;
         cin>>l>>r;
         cout<<query(1,0,n-1,l,r)<<endl;
     }
    }
    return 0;
    
}
