/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        map <int, int> m;
        for (auto i : nums) {
            m[i]++;
        }
        for (int i=1; i<=nums.size(); i++) {
            if (!m[i]) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
// @lc code=end

