
/* Graph Representation - Adjacency list 

   Solution by Supriya2301
   
*/   

#include<bits/stdc++.h>
using namespace std;

int main()
{
	// user input number of vertex and edges
	int v,e;
	cin>>v>>e;
	
	//making array of vectors
	vector<int>adj[v+1];
	
	// connecting vertices
	for(int i=0;i<e;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	// displaying graph connection
	for(int i=1;i<=v;i++)
	{
		cout<<i<< "-->"<<" ";
		for(int j=0;j<adj[i].size();j++)
		{
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	
	
	return 0;
}
