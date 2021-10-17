/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 */

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map <int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int max=0;
        for(auto it=m.begin();it!=m.end();it++){
            if(m.find(it->first+1)!=m.end()){
                max=max>it->second+m[it->first+1]?max:it->second+m[it->first+1];
            }
        }
        return max;
    }
};
// @lc code=end

