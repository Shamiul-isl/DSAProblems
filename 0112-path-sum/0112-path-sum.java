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
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if (root == null) {
          return false;
        }

        if (root.val == targetSum && (root.left == null && root.right == null)) {
          return true;
        }

        boolean left;
        if (root.left != null) {
          left = hasPathSum(root.left, targetSum - root.val);
          if (left)
            return left;
        }

        if (root.right != null) {
          return hasPathSum(root.right, targetSum - root.val);
        }

        return false;
    }
}