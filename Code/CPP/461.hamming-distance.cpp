/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = x^y;
        int count = 0;
        while (result) {
            if (result & 1) {
                count++;
            }
            result >>= 1;
        }
        return count;
    }
};
// @lc code=end

