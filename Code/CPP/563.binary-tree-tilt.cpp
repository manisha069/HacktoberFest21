/*
 * @lc app=leetcode id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
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
class Solution
{
public:
    int findTilt(TreeNode *root)
    {
        int res = 0;
        if (root == nullptr)
            return res;
        res += findTilt(root->left);
        res += findTilt(root->right);
        res += abs(sum(root->left) - sum(root->right));
        return res;
    }
    int sum(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return root->val + sum(root->left) + sum(root->right);
    }
};
// @lc code=end
