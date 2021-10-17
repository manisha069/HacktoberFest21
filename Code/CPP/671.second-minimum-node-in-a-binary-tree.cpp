/*
 * @lc app=leetcode id=671 lang=cpp
 *
 * [671] Second Minimum Node In a Binary Tree
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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        long long min = root->val, secondMin = INT_MAX;
        secondMin ++;
        dfs(root, min, secondMin);
        return secondMin-1 == INT_MAX ? -1 : secondMin;
    }
private:
    void dfs(TreeNode* root, long long& min, long long& secondMin) {
        if (!root) return;
        if (root->val > min && root->val < secondMin) secondMin = root->val;
        dfs(root->left, min, secondMin);
        dfs(root->right, min, secondMin);
    }
};
// @lc code=end

