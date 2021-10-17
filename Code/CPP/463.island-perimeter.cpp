/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    if (i==0 || grid[i-1][j] == 0) {
                        count++;
                    }
                    if (i==row-1 || grid[i+1][j] == 0) {
                        count++;
                    }
                    if (j==0 || grid[i][j-1] == 0) {
                        count++;
                    }
                    if (j==col-1 || grid[i][j+1] == 0) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
// @lc code=end

