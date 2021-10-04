/*
 * @lc app=leetcode id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root==nullptr) return 0;
        int max_depth = 0;
        for (auto child : root->children) {
            max_depth = max(max_depth, maxDepth(child));
        }
        return max_depth + 1;
    }
};
// @lc code=end

