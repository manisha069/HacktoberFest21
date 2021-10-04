/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 */

// @lc code=start
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ret;
        vector<int> score_copy(score);
        sort(score_copy.begin(), score_copy.end(), greater<int>());
        for (int i = 0; i < score.size(); i++) {
            if (score[i] == score_copy[0]) {
                ret.push_back("Gold Medal");
            } else if (score[i] == score_copy[1]) {
                ret.push_back("Silver Medal");
            } else if (score[i] == score_copy[2]) {
                ret.push_back("Bronze Medal");
            } else {
                ret.push_back(to_string(find(score_copy.begin(), score_copy.end(), score[i] ) - score_copy.begin()+1));
            }
        }
        return ret;
    }
};
// @lc code=end

