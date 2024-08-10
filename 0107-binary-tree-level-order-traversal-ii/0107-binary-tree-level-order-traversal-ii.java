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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> result = new LinkedList<List<Integer>>();

        if (root == null) {
          return result;
        }
        // TODO: Write your code here
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.offer(root);
        while (!queue.isEmpty()) {
          int levelSize = queue.size();
          List<Integer> level = new ArrayList<>();

          for (int i = 0; i < levelSize; i++) {
            TreeNode cur = queue.poll();
            level.add(cur.val);

            if (cur.left != null)
              queue.offer(cur.left);

            if (cur.right != null)
              queue.offer(cur.right);
          }

          result.add(0, level);
        }
        return result;
    }
}