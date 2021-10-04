
/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<TreeNode*> v1,v2;
        vector<double> ans;
        if(root==NULL) return ans;
        v1.push_back(root);
        while(!v1.empty()){
            double sum=0;
            int n=v1.size();
            for(int i=0;i<n;i++){
                sum+=v1[i]->val;
                if(v1[i]->left) v2.push_back(v1[i]->left);
                if(v1[i]->right) v2.push_back(v1[i]->right);
            }
            ans.push_back(sum/n);
            v1=v2;
            v2.clear();
        }
        return ans;
    }
};
// @lc code=end

