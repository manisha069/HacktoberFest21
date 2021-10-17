/*
 * @lc app=leetcode id=551 lang=cpp
 *
 * [551] Student Attendance Record I
 */

// @lc code=start
class Solution {
public:
    bool checkRecord(string s) {
        int a = 0, l = 0;
        for (char c : s) {
            if (c == 'A') {
                a++;
                l=0;
                if (a >=2) return false;
            } else if (c == 'L') {
                l++;
                if (l > 2) return false;
            } else {
                l = 0;
            }
        }
        return true;
    }
};
// @lc code=end

