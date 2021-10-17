/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if(m*n!=r*c) return mat;
        vector<vector<int>> res;
        vector <int> flat;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                flat.push_back(mat[i][j]);
            }
        }
        for(int i=0;i<r;i++){
            vector<int> row;
            for(int j=0;j<c;j++){
                row.push_back(flat[i*c+j]);
            }
            res.push_back(row);
        }
        return res;
    }
};
// @lc code=end

