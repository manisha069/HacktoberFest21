/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode* root) {
        // if (root == nullptr)return {};
        // vector<int> ans={root->val};
        // if(root->left){
        //     vector<int>left = preorderTraversal(root->left);
        //     ans.insert(ans.end(), left.begin(), left.end());
        // }
        // if(root->right){
        //     vector<int>right = preorderTraversal(root->right);
        //     ans.insert(ans.end(), right.begin(), right.end());
        // }
        // return ans;
        vector<int> ans;
        vector<TreeNode*> stack;
        stack.push_back(root);
        while(!stack.empty()){
            TreeNode* node = stack.back();
            stack.pop_back();
            if(node){
                ans.push_back(node->val);
                stack.push_back(node->right);
                stack.push_back(node->left);
            }
        }
        return ans;
    }
};
// @lc code=end

