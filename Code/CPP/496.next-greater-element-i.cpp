/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        for (int i = 0; i < nums2.size(); i++) {
            for (int j = i; j<nums2.size(); j++) {
                if (nums2[j] > nums2[i]) {
                    m[nums2[i]] = nums2[j];
                    break;
                }
            }
            if (!m[nums2[i]]){
                m[nums2[i]] = -1;
            }
        }
        vector<int> ret;
        for (int i = 0; i < nums1.size(); i++) {
            ret.push_back(m[nums1[i]]);
        }
        return ret;
    }
};
// @lc code=end

