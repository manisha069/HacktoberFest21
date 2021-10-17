/*
 * @lc app=leetcode id=575 lang=cpp
 *
 * [575] Distribute Candies
 */

// @lc code=start
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        map<int,int> m;
        for(int i=0;i<candyType.size();i++){
            m[candyType[i]]++;
        }
        if(m.size()<=candyType.size()/2){
            return m.size();
        }
        return candyType.size()/2;
    }
};
// @lc code=end

