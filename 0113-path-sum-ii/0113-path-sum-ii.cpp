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
  vector<vector<int>> pathSum(TreeNode *root, int sum) {
    return findPath(root, vector<int>(), 0, sum);
  }

  vector<vector<int>> findPath(TreeNode *cur, vector<int> res, int curSum, int targetSum) {
    vector<vector<int>> total;
    if (!cur) return total;

    int sum = cur->val + curSum;
    res.push_back(cur->val);
    
    if (cur->left == nullptr && cur->right == nullptr && cur->val == targetSum) {
      total.push_back(res);
    } else {
        if (cur->left) {
          vector<vector<int>> l = findPath(cur->left, res, sum, targetSum - cur->val);
          if (l.size() > 0) total.insert(total.end(), l.begin(), l.end());
        }

        if (cur->right) {
          vector<vector<int>> r = findPath(cur->right, res, sum, targetSum - cur->val);
          if (r.size() > 0) total.insert(total.end(), r.begin(), r.end());
        }
    }

    return total;

  }
};