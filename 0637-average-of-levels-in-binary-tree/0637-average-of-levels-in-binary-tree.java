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
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> result = new ArrayList<>();

        if (root == null) {
          return result;
        }
        // TODO: Write your code here
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
          long levelSize = queue.size();
          long sum = 0;
          for (int i = 0; i < levelSize; i++) {
            TreeNode cur = queue.poll();
            sum += cur.val;
            if (cur.left != null)
              queue.offer(cur.left);
            if (cur.right != null)
              queue.offer(cur.right);
          }
          result.add(((double) sum) / (double) levelSize);
        }
        return result;
    }
}