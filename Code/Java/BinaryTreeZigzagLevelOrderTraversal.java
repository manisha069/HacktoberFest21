// Solution to https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null) {
            return ans;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        boolean leftToRight = true;
        queue.add(root);
        while (!queue.isEmpty()) {
            int size = queue.size();
            List<Integer> temp = new ArrayList<>();
            while (size-- > 0) {
                TreeNode removed = queue.remove();
                temp.add(removed.val);
                if (removed.left != null) {
                    queue.add(removed.left);
                }
                if (removed.right != null) {
                    queue.add(removed.right);
                }
            }
            if (!leftToRight) {
                Collections.reverse(temp);
            }
            ans.add(temp);
            leftToRight = !leftToRight;
        }
        return ans;
    }
}