/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string res;
        if (num<0){
            res+='-';
            num=-num;
        }
        vector<int> digits;
        while (num) {
            digits.push_back(num % 7);
            num /= 7;
        }
        for (int i = digits.size() - 1; i >= 0; i--) {
            res += to_string(digits[i]);
        }
        return res;
    }
};
// @lc code=end

