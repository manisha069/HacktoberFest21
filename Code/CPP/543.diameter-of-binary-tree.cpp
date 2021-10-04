/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int diameterOfBinaryTree(TreeNode* root) {
        int left = (root->left == nullptr) ? 0 : diameterOfBinaryTree(root->left);
        int right = (root->right == nullptr) ? 0 : diameterOfBinaryTree(root->right);
        int max_diameter = max(left, right);
        int mid = depthOfBinaryTree(root->left) + depthOfBinaryTree(root->right);
        return max(max_diameter, mid);
    }
    int depthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = (root->left) ? depthOfBinaryTree(root->left) : 0;
        int right = (root->right) ? depthOfBinaryTree(root->right) : 0;
        return max(left, right) + 1;
    }
};
// @lc code=end

