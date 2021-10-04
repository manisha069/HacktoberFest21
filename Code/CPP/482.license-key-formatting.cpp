/*
 * @lc app=leetcode id=482 lang=cpp
 *
 * [482] License Key Formatting
 */

// @lc code=start
class Solution
{
public:
    string licenseKeyFormatting(string s, long k)
    {
        string ans;
    int cnt = 0 , n = s.size();
    for(int i = n - 1 ; i >= 0 ; i--) {
        if(s[i] != '-') {
            if(cnt == k) {
                ans += '-';
                cnt = 0;
            }
            cnt++;
            if(s[i] >= 'a' && s[i] <= 'z') {
                s[i] += 'A' - 'a';
            }
            ans += s[i];
        }
    }
    reverse(ans.begin() , ans.end());
    return ans;
    }
};
// @lc code=end
