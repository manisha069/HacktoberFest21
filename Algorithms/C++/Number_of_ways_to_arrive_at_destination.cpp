
// Problem Link - https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

// this question can be easily solved using dijkrat's algorithm.
// just maintain a ways array that will store the number of ways to reach that node. 
// as dijkrata will give the shortest path, if that path is again visited with same distance then one more path is added to the answer.
    

class Solution {
public:
    #define lli long long int
    unordered_map<lli,vector<pair<lli,lli> > >adj;
    int countPaths(int n, vector<vector<int>>& roads) {
        
        int m=roads.size();
        for(int i=0;i<m;i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<lli,lli>, vector<pair<lli,lli> >, greater<pair<lli,lli> > >pq;
        vector<long long int> dist(n,LONG_MAX);
        vector<long long int> ways(n);
        pq.push({0,0});
        ways[0]=1;
        dist[0]=0;
        while(!pq.empty())
        {
            pair<lli,lli> p=pq.top();
            pq.pop();
            for(auto nbr:adj[p.second])
            {
                long long int x=p.first+nbr.second;
                if(dist[nbr.first]>(x))
                {
                    dist[nbr.first]=x;
                    ways[nbr.first]=ways[p.second];
                    cout<<nbr.first<<" ";
                    pq.push({dist[nbr.first],nbr.first});
                }
                else if(dist[nbr.first]==(x))
                {
                    ways[nbr.first]=(ways[nbr.first]+ways[p.second]);
                    ways[nbr.first]%=1000000007;
                }
            }
        }
        return ways[n-1];
    }
};