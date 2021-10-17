/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        int flag=0;
        string ret;
        for(int i=0;i<n;i+=k){
            if(flag==0){
                for(int j=i+k-1;j>=i;j--){
                    if(j<n) ret+=s[j];
                }
            } else {
                for(int j=i;j<i+k;j++){
                    if(j<n) ret+=s[j];
                }
            }
            flag^=1;
        }
        return ret;
    }
};
// @lc code=end

