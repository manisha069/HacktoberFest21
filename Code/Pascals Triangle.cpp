/*Given an integer numRows, return the first numRows of Pascal's triangle.*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);
        ans[0].resize(1);
        ans[0][0]=1;
        if(numRows==0)
            return ans;
       
        for(int i=1;i<numRows;i++){
            ans[i].resize(i+1);
            ans[i][0]=1;
            ans[i][i]=1;
            for(int j=1;j<i;j++){
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
                
            }
        }
        return ans;
        
    }

int main(){
  int rows;
  cin>>rows;
  vector<vector<int>>ans=generate(rows);
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++)
      cout<<ans[i][j]<<"  ";
    cout<<endl;
  }
  return 0;
}
