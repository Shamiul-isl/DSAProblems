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

        queue<TreeNode*> queue;
        queue.push(root);
        int leftOrRight = 0;

        while (queue.size() > 0) {
          int curSize = queue.size();
          vector<int> temp(curSize);

          for (int i = 0; i < curSize; i++) {
            TreeNode *cur = queue.front();
            queue.pop();

            if (leftOrRight == 0) {
              temp[i] = cur->val;
            } else {
              temp[curSize - 1 - i] = cur->val;
            }

            if (cur->left) queue.push(cur->left);
            if (cur->right) queue.push(cur->right);  
          }

          result.push_back(temp);
          leftOrRight ^= 1;
        }

        return result;
    }
};