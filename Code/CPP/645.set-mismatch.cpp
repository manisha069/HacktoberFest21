/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[i]=0;
        }
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int a=0,b=0;
        for(int i=1;i<=n;i++){
            if(m[i]==0){
                a=i;
            }
            if(m[i]==2){
                b=i;
            }
        }
        return vector<int>{b,a};
    }
};
// @lc code=end

