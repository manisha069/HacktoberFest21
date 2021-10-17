/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        double max = sum;
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            max = max > sum ? max : sum;
        }
        return max / k;
    }
};
// @lc code=end

