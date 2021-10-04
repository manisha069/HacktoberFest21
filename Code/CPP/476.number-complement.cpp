/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        int highest2 = 0;
        int numcpy = num;
        while (num) {
            highest2 <<= 1;
            highest2++;
            num >>= 1;
        }
        return highest2 - numcpy;
    }
};
// @lc code=end

