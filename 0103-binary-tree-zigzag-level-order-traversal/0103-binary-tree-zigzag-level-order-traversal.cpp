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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if (!root) return result;

        deque<TreeNode*> queue;
        queue.push_front(root);
        int leftOrRight = 1;

        while (queue.size() > 0) {
          int curSize = queue.size();
          vector<int> temp;

          for (int i = 0; i < curSize; i++) {
            TreeNode *cur;  

            if (leftOrRight == 0) {
              cur = queue.back();
              queue.pop_back();
              if (cur->right) queue.push_front(cur->right);
              if (cur->left) queue.push_front(cur->left);
            } else {
              cur = queue.front();
              queue.pop_front();              
              if (cur->left) queue.push_back(cur->left);
              if (cur->right) queue.push_back(cur->right);
            }
            
            temp.push_back(cur->val);
          }

          result.push_back(temp);
          leftOrRight ^= 1;
        }
        // TODO: Write your code here

        return result;
    }
};