/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        queue<Node*> queue;
        queue.push(root);

        while (queue.size() > 0) {
          int curSize = queue.size();

          Node *prev = nullptr;
          for (int i = 0; i < curSize; i++) {
            Node *cur = queue.front();
            queue.pop();

            if (cur->left) queue.push(cur->left);
            if (cur->right) queue.push(cur->right);

            if (prev == nullptr) {
              prev = cur;
              continue;
            }

            prev->next = cur;
            prev = cur;
          }

          prev->next = nullptr;
        }
        return root;
    }
};