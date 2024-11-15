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
    bool isValidSequence(TreeNode* root, const vector<int>& arr) {
        return findPathRecursive(root, 0, arr);
    }

    bool findPathRecursive(TreeNode *cur, int index, const vector<int> &sequence) {
        if (!cur) return false;

        if (index >= sequence.size() || cur->val != sequence[index]) return false;

        if (!cur->left && !cur->right && index == sequence.size() - 1) {
          return true;
        }
    
        return findPathRecursive(cur->left, index+1, sequence) || findPathRecursive(cur->right, index+1, sequence);
    }

};