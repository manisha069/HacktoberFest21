/*
 * @lc app=leetcode id=495 lang=cpp
 *
 * [495] Teemo Attacking
 */

// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int result=0;
        for (int i = timeSeries.size()-1; i >= 0; i--) {
            if (i==timeSeries.size()-1) {
                result+=duration;
            } else if (timeSeries[i+1]-timeSeries[i]<=duration) {
                result+=timeSeries[i+1]-timeSeries[i];
            } else {
                result+=duration;
            }
        }
        return result;
    }
};
// @lc code=end

