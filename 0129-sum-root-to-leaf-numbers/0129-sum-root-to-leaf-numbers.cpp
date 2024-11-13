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
    int sumNumbers(TreeNode* root) {
        int total = 0;
        allSums(root, 0, total);
        return total;
      }

      void allSums(TreeNode *cur, int curDigits, int &total) {
        if (!cur) return;

        int temp = 10 * curDigits + cur->val;
        if (!cur->left && !cur->right) {  
          total += temp;
        }

        allSums(cur->left, temp, total);
        allSums(cur->right, temp, total);
      }
};