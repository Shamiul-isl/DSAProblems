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
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        vector<int> seen;
        sumAllPaths(root, count, (long)targetSum, seen);
        return count;
      }

  void sumAllPaths(TreeNode *cur, int &count, long targetSum, vector<int> &seen) {
        if (!cur) return;

        seen.push_back(cur->val);
        targetSum -= cur->val;
      
        if (targetSum == 0) {
            count++;
        }
        long temp = targetSum, i = 0, curSize = seen.size() - 1;
        while (i < curSize) {
            temp += seen[i];
            if (temp == 0) {
              count++;
              // break;
            }

            i++;
        }

//     if (targetSum == 0) {
//       count++;
//     } else {
//       int temp = targetSum, i = 0, curSize = seen.size() - 1;
//       while (i < curSize) {
//         temp += seen[i];
//         if (temp == 0) {
//           count++;
//           break;
//         }

//         i++;
//       }
//     }

    sumAllPaths(cur->left, count, targetSum, seen);
    sumAllPaths(cur->right, count, targetSum, seen);

    seen.pop_back();

  }
};