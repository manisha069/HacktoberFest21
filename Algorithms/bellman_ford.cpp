#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int src, int V, vector<vector<int>> edges)
{
    //Initially all the vertices will have INT_MAX distance from source node
    vector<int> dist(V + 1, INT_MAX);
    dist[src] = 0;

    //relaxing all the edges V-1 times
    for (int i = 0; i < V - 1; i++)
    {
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            //to avoid overflow of integer, we check if dist[u] does not equals INT_MAX
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    //cheking for negative edge cycle
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
        {
            cout << "Negative Edge Cycle found! \n";
            exit(0);
        }
    }

    return dist;
}

int main()
{
    int n, m, src;
    vector<vector<int>> edges;

    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;
    cout << "Enter the source node: ";
    cin >> src;
    cout << "Enter the nodes (u->v) and the weight of the edges\n";
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    //The function returns a vector containing the distances of all vertices from source node
    vector<int> dist = bellman_ford(src, n, edges);

    cout << "The distances of all vertices from source node:\n";
    for (int i = 1; i <= n; i++)
    {
        cout << i << "->" << dist[i] << endl;
    }

    return 0;
}