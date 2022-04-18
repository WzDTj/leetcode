#include "../structures/tree_node.cpp"
#include <stack>

using namespace std;

class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    stack<TreeNode *> stk;

    while (root != nullptr || !stk.empty()) {
      while (root != nullptr) {
        stk.push(root);
        root = root->left;
      }

      root = stk.top();
      stk.pop();
      if (!--k) {
        return root->val;
      }
      root = root->right;
    }

    return 0;
  }
};
