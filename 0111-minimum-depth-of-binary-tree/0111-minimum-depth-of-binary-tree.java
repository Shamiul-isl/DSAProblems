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
    public int minDepth(TreeNode root) {
        int minimumTreeDepth = 0;
        // TODO: Write your code here
        if (root == null) 
          return minimumTreeDepth;

        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
          int levelSize = queue.size();
          for (int i = 0; i < levelSize; i++) {
            TreeNode cur = queue.poll();
            if (cur.left == null && cur.right == null) {
              return ++minimumTreeDepth;
            }
            if (cur.left != null)
              queue.offer(cur.left);
            if (cur.right != null)
              queue.offer(cur.right);
          }
          minimumTreeDepth++;
        }
        
        return ++minimumTreeDepth;
    }
}