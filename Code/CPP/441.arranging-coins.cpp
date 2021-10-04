/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        long long start = 0, end = n;
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            if (mid * (mid + 1) / 2 > n) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start - 1;
    }
};
// @lc code=end

