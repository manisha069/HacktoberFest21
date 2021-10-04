// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem530.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
    int getMinimumDifference(TreeNode* root) {
        int min_diff = INT_MAX;
        int prev = INT_MIN;
        inorder(root, prev, min_diff);
        return min_diff;
    }

    void inorder(TreeNode* root, int& prev, int& min_diff) {
        if (!root) return;
        inorder(root->left, prev, min_diff);
        if (prev != INT_MIN) {
            min_diff = min(min_diff, root->val - prev);
        }
        prev = root->val;
        inorder(root->right, prev, min_diff);
    }

};
// @lc code=end

