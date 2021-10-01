#include <bits/stdc++.h>
using namespace std;
#define maxn 40005
/*We maintain a visited array to keep track of what all nodes have already been visited
  And an adjacency list(adj) can be formed using the given input array(A)*/
int visited[maxn];
vector<int> adj[maxn];
vector<int> A;

//mx stores the answer at all times
int mx;

/*DFS function runs a DFS from the source node (node), and keeps updating the max distance until all nodes are visited
  nd stores the node which is found to be at farthest distance from the source node (node)*/
void dfs(int node, int dist, int& nd)
{
    if (dist > mx) {
        mx = dist;
        nd = node;
    }

    visited[node] = 1;
    for (int i = 0; i < adj[node].size(); i++) {
        //If any node in the source node's adjacency list is found to be unvisited, we call a DFS with that node as a source and distance dist+1
        int s = adj[node][i];
        if (visited[s]) {
            continue;
        }
        dfs(s, dist + 1, nd);
    }
}

//solve function calls DFS twice as discussed above
int solve(int n)
{

    //If there is only one node, then the largest distance from that node is 0
    if (n == 1) {
        return 0;
    }

    //Call DFS from root node
    mx = 0;
    int nd = -1;
    dfs(0, 0, nd);

    //Reset the visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    //Call DFS from the node found to be farthest from root
    mx = 0;
    int md = -1;
    dfs(nd, 0, md);

    return mx;
}

int main()
{
    int n;
    cin >> n;

    for (int itr = 0; itr < n; itr++) {
        int x;
        cin >> x;
        A.push_back(x);
    }

    //Generate Adjacency list from input array A
    for (int i = 0; i < n; i++) {
        if (A[i] == -1) {
            continue;
        }
        adj[i].push_back(A[i]);
        adj[A[i]].push_back(i);
    }

    cout << solve(n) << endl;
}
//   Time Complexity: O(n)
//   Space Complexity: O(n)*/
