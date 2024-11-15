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
        bool res = findPathRecursive(root,arr, 0);
        return res;
    }

//     bool tryPath(TreeNode *cur, int index, const vector<int> &sequence) {
//         if (!cur) return false;

//         if (cur->val != sequence[index]) return false;

//         if (!cur->left && !cur->right && index == sequence.size() - 1)
//           return true;
//         else {
//           bool left, right;
//           if (cur->left && index < sequence.size() - 1) left = tryPath(cur->left, index+1, sequence);
//           if (cur->right && index < sequence.size() - 1) right = tryPath(cur->right, index+1, sequence);

//           if (left || right) {
//             return true;
//           }

//           return false;
//         }
//     }
    bool findPathRecursive(TreeNode *currentNode, const vector<int> &sequence,
                                int sequenceIndex) {
    if (currentNode == nullptr) {
      return false;
    }

    if (sequenceIndex >= sequence.size() || currentNode->val != sequence[sequenceIndex]) 
    {
      return false;
    }

    // if the current node is a leaf, add it is the end of the sequence, we have found 
    // a path!
    if (currentNode->left == nullptr && currentNode->right == nullptr &&
        sequenceIndex == sequence.size() - 1) {
      return true;
    }

    // recursively call to traverse the left and right sub-tree
    // return true if any of the two recursive call return true
    return findPathRecursive(currentNode->left, sequence, sequenceIndex + 1) ||
          findPathRecursive(currentNode->right, sequence, sequenceIndex + 1);
  }
};