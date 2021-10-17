
/*
 * @lc app=leetcode id=492 lang=cpp
 *
 * [492] Construct the Rectangle
 */

// @lc code=start
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int L,W;
        int r = sqrt(area);
        for (W = r; W > 0; W--) {
            if (area % W == 0) {
                L = area / W;
                return {L, W};
            }
        }
        return {L, W};
    }
};
// @lc code=end

