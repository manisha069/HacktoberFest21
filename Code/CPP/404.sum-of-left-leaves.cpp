/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        int sum = 0;
        if (root->left) {
            if (root->left->left == nullptr && root->left->right == nullptr) {
                sum += root->left->val;
            } else {
                sum += sumOfLeftLeaves(root->left);
            }
        }
        if (root->right) {
            sum += sumOfLeftLeaves(root->right);
        }
        return sum;
    }
};
// @lc code=end

