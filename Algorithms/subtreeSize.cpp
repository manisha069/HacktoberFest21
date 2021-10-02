#include <bits/stdc++.h>
using namespace std;


vector<int> arr[50];
//Visited array, it stores wheather the node is visited or not
vector<int> vis(50, 0);
//Subsize array, it stores the subtree size of each node
vector<int> subsize(50, 0);

int dfs(int node)
{
    vis[node] = 1;
    int curr_size = 1;
    for (auto child : arr[node])
    {
        if (vis[child] == 0)
            curr_size += dfs(child);
    }
    subsize[node] = curr_size;
    return curr_size;
}

int main()
{
    int nodes, edges, u, v;
    cout << "Enter nodes and number of edges: ";
    cin >> nodes >> edges;
    cout << "Enter the edges:- \n";
    for (int i = 1; i <= edges; i++)
    {
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    dfs(1);
    cout << "Subtree size array : \n";
    for (int i = 1; i <= nodes; i++)
    {
        cout << subsize[i] << " ";
    }
}
