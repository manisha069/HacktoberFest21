/*
 * @lc app=leetcode id=598 lang=cpp
 *
 * [598] Range Addition II
 */

// @lc code=start
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_x = m, min_y = n;
        for (auto& op : ops) {
            min_x = min(min_x, op[0]);
            min_y = min(min_y, op[1]);
        }
        return min_x * min_y;
    }
};
// @lc code=end

