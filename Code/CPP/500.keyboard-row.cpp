/*
 * @lc app=leetcode id=500 lang=cpp
 *
 * [500] Keyboard Row
 */

// @lc code=start
class Solution {
public:
string str1 = "qwertyuiop";
string str2 = "asdfghjkl";
string str3 = "zxcvbnm";
    bool inOneLine(string s){
        string str;
        char f;
        if (s[0]>='A' && s[0]<='Z') {
            f =s[0] - 'A'+'a';
        } else {
            f = s[0];
        }
        if (str1.find(f) != string::npos) {
            str = str1;
        }
        else if (str2.find(f) != string::npos) {
            str = str2;
        }
        else if (str3.find(f) != string::npos) {
            str = str3;
        }
        for (char c:s){
            char temp;
            if (c>='A' && c<='Z') {
                temp = c - 'A'+'a';
            } else {
                temp = c;
            }
            if (str.find(temp) == string::npos) return false;
        }
        return true;
    }
    vector<string> findWords(vector<string>& words) {
        vector<string> ret;
        for (auto s : words) {
            if (inOneLine(s)) ret.push_back(s);
        }
        return ret;
    }
};
// @lc code=end

