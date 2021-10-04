/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        int flag=0;
        int len = s.size();
        int max = 0;
        map<char,int> m;
        for (auto c: s) {
            m[c]++;
        }
        for (auto p: m) {
            if (p.second % 2 == 1) {
                flag = 1;
            }
            max += p.second/2;
        }
        return (max*2)+flag;
    }
};
// @lc code=end

