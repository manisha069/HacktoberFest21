/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
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
    vector<int> preorder(Node* root) {
        vector<int> ret;
        if (root == nullptr) return ret;
        ret.push_back(root->val);
        for (auto child : root->children) {
            vector <int> tmp = preorder(child);
            ret.insert(ret.end(), tmp.begin(), tmp.end());
        }
        return ret;
    }
};
// @lc code=end

