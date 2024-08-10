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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        // TODO: Write your code here
        if (root == null) {
            return result;
        }
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.offer(root);
//         while (true) {
//             int levelSize = 
//             List<Integer> level = new ArrayList<>();
//             while (!queue.isEmpty()) {
//                 TreeNode cur = queue.remove();
//                 level.add(cur.val);
//                 if (cur.left != null)
//                   children.add(cur.left);
//                 if (cur.right != null)
//                   children.add(cur.right);
//             }
            
//             result.add(level);
            
//             for (TreeNode c: children) {
//                 queue.offer(c);
//             }
            
//             if (queue.isEmpty()) {
//                 break;
//             }
//         }
        
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
            result.add(level);
        }
        
        return result;
    }
}