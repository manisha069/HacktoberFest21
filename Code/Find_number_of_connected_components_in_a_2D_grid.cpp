//The idea is to use DFS over grid.
#include<bits/stdc++.h>
using namespace std;


int grid[100][100];
bool visited[100][100];
int dx[]={-1, 0, 1, 0};
int dy[]={0, 1, 0, -1};

bool isValid(int x, int y, int n, int m)
{
	if(x<1 || x>n || y<1 || y>m)
	return false;
	
	if(visited[x][y] || grid[x][y]==0)
	return false;
	
	return true;
}

void dfs(int x, int y, int n, int m)
{
	
	visited[x][y] = true;
	
	for(int i=0;i<4;i++)
	{
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if(isValid(nx,ny,n,m))
		{
			dfs(nx,ny,n,m);	
		} 
	}
}


int main()
{
	memset(visited, false, sizeof(visited));
	memset(grid, 0, sizeof(grid));
	int n,m,c=0;
	cout<<"enter the number of rows and columns : ";
	cin>>n>>m;
	
	cout<<"enter the values in grid : ";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		cin>>grid[i][j];
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(grid[i][j]!=0 && visited[i][j]==false)
			{
				dfs(i,j,n,m);
				c++;
			}	
		}
	}
	
	cout<<"\nThe connected components are : "<<c<<endl;
	
	
}