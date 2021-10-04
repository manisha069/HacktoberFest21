/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        string res;
        string temp="";
        for (auto c: s){
            if (c == ' '){
                reverse(temp.begin(), temp.end());
                res.append(temp);
                res.push_back(' ');
                temp = "";
            } else {
                temp.push_back(c);
            }
        }
        reverse(temp.begin(), temp.end());
        res.append(temp);
        return res;
    }
};
// @lc code=end

