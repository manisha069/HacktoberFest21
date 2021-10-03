// get MAZE Paths using Recursion
// Solution by : Supriya2301

#include<bits/stdc++.h>
using namespace std;

//function implementation
vector<string> getMazePaths(int sr,int sc,int dr,int dc)
{
	//base case to stop recursion and storing the result into vector
	if(sr == dr && sc == dc)
	{
		vector<string> v;
		v.push_back("");
		return v;
	}
	vector<string> hpaths;
	vector<string> vpaths;

  // if not reached to the destination column or row, keep calling the function

	if(sc<dc)
	{
		hpaths = getMazePaths(sr,sc+1,dr,dc);
	}
	if(sr<dr)
	{
		vpaths = getMazePaths(sr+1,sc,dr,dc);
	}

	// storinh the result into one vector which is to be returned
	vector<string> res;
	for(string h:hpaths)
	{
		res.push_back("h"+h);
	}
	for(string v:vpaths)
	{
		res.push_back("v"+v);
	}
	
	return res;
	
}

int main()
{
	int n;
	cin>>n;
	// calling function with argument row start and end index and destination start and end index.
	vector<string> res = getMazePaths(1,1,n,n);

	// for every result in vector, printing the paths
	for(string s:res)
	{
		cout<<s<<"   ";
	}
	
	return 0;
}
