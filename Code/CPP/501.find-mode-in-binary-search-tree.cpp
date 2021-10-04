/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
int cur_val = 0;
int cur_cnt = 0;
int max_cnt = 0;
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }
private:
    void traverse(TreeNode* root, vector<int>& res) {
        if (!root) return;
        traverse(root->left, res);
        if (cur_val == root->val) {
            cur_cnt++;
        } else {
            cur_val = root->val;
            cur_cnt = 1;
        }
        if (cur_cnt == max_cnt) {
            res.push_back(cur_val);
        } else if (cur_cnt > max_cnt) {
            res.clear();
            res.push_back(cur_val);
            max_cnt = cur_cnt;
        }
        traverse(root->right, res);
    }
};
// @lc code=end

