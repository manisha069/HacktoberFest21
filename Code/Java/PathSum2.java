// Following is the solution to Leetcode problem Path Sum II
// You can use this if you are stuck or need some help
// Link to the problem https://leetcode.com/problems/path-sum-ii/
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null) {
            return ans;
        }
        List<Integer> sub = new ArrayList<>();
        helper(root, sum, ans, sub);
        return ans;
    }
    public void helper(TreeNode root, int sum, List<List<Integer>> ans, List<Integer> sub) {
        if (root == null) {
            return;
        }
        sub.add(root.val);
        if(root.left == null && root.right == null) {
            if (sum == root.val) {
                ans.add(new ArrayList<Integer>(sub));
            }
        }
        helper(root.left, sum - root.val, ans, sub);
        helper(root.right, sum - root.val, ans, sub);
        sub.remove(sub.size() - 1);
    }
}