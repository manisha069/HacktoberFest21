/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 */

// @lc code=start
class Solution {
public:
    string toHex(int num) {
        string hex = "0123456789abcdef";
        string ans;
        if(num==0) return "0";
        while (num>0) {
            ans = hex[num & 15] + ans;
            num >>= 4;
        }
        if(num<0){
            ans = "00000000";
            num++;
            num*=-1;
            int i=7;
            while(i>=0){
                ans[i] = hex[15 -(num & 15)];
                num >>= 4;
                i--;
            }
        }
        return ans;
    }
};
// @lc code=end

