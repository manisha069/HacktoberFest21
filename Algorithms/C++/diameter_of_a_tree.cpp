// Input format
// First line contains an integer n (no of nodes)
// N-1 lines contain the nodes u and v that describes each edge
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N =1e6;
vector<int> adj[N],dist(N),vis(N);
void bfs(int node){
    vis[node]=1;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        node=q.front();
        q.pop();
        for(int child : adj[node]){
            if(vis[child]==0){
                vis[child]=1;
                dist[child]=dist[node]+1;
                q.push(child);
            }
        }
    }
}
int main(){
    int i,n,node,mx=0;
    cin>>n;
    for(i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dist.clear();
    vis.clear();
    bfs(1);
    for(i=1;i<=n;i++){
        if(dist[i]>mx){
            mx=dist[i];
            node=i;
        }
    }
    dist.clear();
    vis.clear();
    bfs(node);
    mx=0;
    for(i=1;i<=n;i++){
        mx=max(mx,dist[i]);
    }
    
    cout<<mx<<endl;
}