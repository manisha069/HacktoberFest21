#include <bits/stdc++.h>
using namespace std;

bool dfs_helper(vector<int> graph[], int node, int parent, int *visited, int color)
{
    //if color equals 1 or 2, it means it is visited
    visited[node] = color;

    for (auto nbr : graph[node])
    {
        if (visited[nbr] == 0)
        {
            //check for neighbour of current node
            bool subprob = dfs_helper(graph, nbr, node, visited, 3 - color);
            if (!subprob)
            {
                return false;
            }
        }
        //Cycle detected
        else if (nbr != parent && visited[nbr] == color)
        {
            return false;
        }
    }

    return true;
}

bool dfs(vector<int> graph[], int N)
{
    //Initially all nodes are marked 0 (not visited)
    int visited[N] = {0};

    bool ans = dfs_helper(graph, 1, -1, visited, 1);

    return ans;
}

int main()
{
    int N, x, y, e;
    cout << "Enter the number of nodes: ";
    cin >> N;
    cout << "Enter the number of edges: ";
    cin >> e;
    N++;

    vector<int> graph[N];

    cout << "Enter the nodes present at each edge\n";
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    if (dfs(graph, N))
    {
        cout << "Bipartite Graph\n";
    }
    else
    {
        cout << "Non Bipartite Graph\n";
    }

    return 0;
}