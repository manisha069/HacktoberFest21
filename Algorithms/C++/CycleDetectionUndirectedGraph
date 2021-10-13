#include<bits/stdc++.h>

using namespace std;

bool check_cycle(int src, vector<int> adj[], vector<bool> &visited, int parent){

    visited[src] = true;

    for(auto it : adj[src]){
        if(!visited[it]){
            if(check_cycle(it,adj,visited,src))
                return true;
        }
        else if(it != parent)
            return true;
    }
    return false;
}


bool isCycle(vector<int> adj[], int n){
    vector<bool> visited(n,false);

    for(int i = 0;i < n;i++){
        if(!visited[i]){
            if(check_cycle(i,adj,visited,-1))
                return true;
        }
    }
    return false;
}

int main(){

    int n,m;
    cin >> n >> m;

    vector<int> adj[n];
    for(int i = 0;i < m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(isCycle(adj,n))
        cout << "Cyclic Graph" << endl;
    else
        cout << "Acyclic Graph" << endl;

}
