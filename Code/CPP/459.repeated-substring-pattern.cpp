/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        for (int i = 1; i < len; i++) {
            if (len % i == 0) {
                string ss = s.substr(0, i);
                bool flag = true;
                for (int j = i; j < len;j+=i) {
                    if (!(s.substr(j, i) == ss)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

