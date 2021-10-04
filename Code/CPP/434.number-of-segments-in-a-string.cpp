/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        s+=" ";
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ' && i > 0 && s[i - 1] != ' ') {
                ++count;
            }
        }
        return count;
    }
};
// @lc code=end

