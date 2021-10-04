/*
 * @lc app=leetcode id=599 lang=cpp
 *
 * [599] Minimum Index Sum of Two Lists
 */

// @lc code=start
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string,int>m1,m2;
        for(int i=0; i<list1.size(); i++){
            m1[list1[i]] = i;
            m2[list1[i]] = 1;
        }
        for(int i=0; i<list2.size(); i++){
            m1[list2[i]] += i;
            m2[list2[i]] += 1;       
        }
        int min = INT_MAX;
        vector<string>ans;
        for(auto it = m1.begin(); it != m1.end(); it++){
            if(it->second < min && m2[it->first] == 2){
                min = it->second;
                ans.clear();
                ans.push_back(it->first);
            }else if(it->second == min && m2[it->first] == 2){
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};
// @lc code=end

