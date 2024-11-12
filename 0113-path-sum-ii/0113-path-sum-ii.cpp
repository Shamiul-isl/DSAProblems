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
    vector<vector<int>> allpaths;
    findPath(root, vector<int>(), sum, allpaths);
    return allpaths;
  }

  void findPath(TreeNode *cur, vector<int> res, int targetSum, vector<vector<int>> &allpaths) {
    if (!cur) return;

    res.push_back(cur->val);
    
    if (cur->left == nullptr && cur->right == nullptr && cur->val == targetSum) {
      allpaths.push_back(res);
    } else {
        if (cur->left) {
          findPath(cur->left, res, targetSum - cur->val, allpaths);
          // if (l.size() > 0) total.insert(total.end(), l.begin(), l.end());
        }

        if (cur->right) {
          findPath(cur->right, res, targetSum - cur->val, allpaths);
          // if (r.size() > 0) total.insert(total.end(), r.begin(), r.end());
        }
    }

    return;

  }
};