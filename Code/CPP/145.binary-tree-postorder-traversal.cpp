/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        // if (root == nullptr) return {};
        // vector<int> ret={};
        // if(root->left) {
        //     vector<int> left = postorderTraversal(root->left);
        //     ret.insert(ret.end(), left.begin(), left.end());
        // }
        // if(root->right) {
        //     vector<int> right = postorderTraversal(root->right);
        //     ret.insert(ret.end(), right.begin(), right.end());
        // }
        // ret.push_back(root->val);
        // return ret;

        if (root == nullptr) return {};
        vector<int> ret={};
        vector<TreeNode*> stack;
        stack.push_back(root);
        while(!stack.empty()){
            TreeNode* node = stack.back();
            stack.pop_back();
            if(node->left){
                stack.push_back(node);
                stack.push_back(node->left);
                node->left = nullptr;
            }else if(node->right){
                stack.push_back(node);
                stack.push_back(node->right);
                node->right = nullptr;
            }else{
                ret.push_back(node->val);
            }
        }
        return ret;
    }
};
// @lc code=end

