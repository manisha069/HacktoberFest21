/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        unordered_map<int,int>mp;
        for(int i=nums2.size()-1 ; i>=0 ; i--) 
            mp[nums2[i]]=i;
        
        for(int i=0 ; i<nums1.size() ; i++)
        {
            int j = mp[nums1[i]]+1;
            while(j<nums2.size() && nums2[j]<nums1[i]) 
                j++;
            
            if(j==nums2.size()) 
                res.push_back(-1);

            else
                res.push_back(nums2[j]);
        }
        return res;
    }
};
// @lc code=end

