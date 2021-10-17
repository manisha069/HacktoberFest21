#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;

vector<int> l[N];
vector<int> vis(N,0),disc(N,0),low(N,0);
int tme = 1;

void dfs(int node, int par) {
	vis[node] = 1;
	//Updating the time of discovery and low of node
	disc[node] = low[node] = tme++;
	int child = 0;
	
	for(auto nbr : l[node]) {
		if(!vis[nbr]) {
			dfs(nbr,node);
			child++;
			
			//Updating the low of node
			low[node] = min(low[node],low[nbr]);
			
			//Bridge detected
			if(low[nbr] > disc[node]) {
				cout<<"Bridge: "<<node<<" "<<nbr<<endl;
			}
			
			//Articulation point (except root node)
			if(par !=0 && low[nbr]>=disc[node]) {
				cout<<"AP: "<<node<<endl;
			}
		}else if(nbr!=par) {
			low[node] = min(low[node],disc[nbr]);
		}
	}
	
	//Articulation point for root node
	if(par==0 && child>1) {
		cout<<"AP: "<<node<<endl;
	}
}

int main() {
	int n,m,u,v,src;
	cout<<"Enter the number of nodes: ";
	cin>>n;
	cout<<"Enter the number of edges: ";
	cin>>m;
	
	cout<<"Enter the edges: \n";
	for(int i=0;i<m;i++) {
		cin>>u>>v;
		l[u].push_back(v);
		l[v].push_back(u);
	}
	
	cout<<"Enter the source node: ";
	cin>>src;
	
	dfs(src,0);
	
	return 0;
}
