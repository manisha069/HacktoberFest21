/*
 * @lc app=leetcode id=453 lang=cpp
 *
 * [453] Minimum Moves to Equal Array Elements
 */

// @lc code=start
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0, min = nums[0];
        for (int num : nums) {
            sum += num;
            min = min < num ? min : num;
        }
        return sum - min * nums.size();
    }
};
// @lc code=end

