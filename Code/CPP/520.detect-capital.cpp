/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for (auto c : word) {
            if (isupper(c)) {
                count++;
            }
        }
        return count == 0 || count == word.size() || (count == 1 && isupper(word[0]));
    }
};
// @lc code=end

