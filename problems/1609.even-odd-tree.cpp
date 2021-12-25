#include "../structures/tree_node.cpp"
#include <queue>

using namespace std;

class Solution {
public:
  bool isEvenOddTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);

    int count = 0;
    while (!q.empty()) {
      int size = q.size();
      int pre = count % 2 ? INT_MAX : INT_MIN;
      for (int i = 0; i < size; ++i) {
        TreeNode *front = q.front();
        q.pop();

        if (count % 2 == front->val % 2)
          return false;
        if (count % 2 == 0 && front->val <= pre)
          return false;
        if (count % 2 == 1 && pre <= front->val)
          return false;

        pre = front->val;

        if (front->left != nullptr)
          q.push(front->left);
        if (front->right != nullptr)
          q.push(front->right);
      }
      ++count;
    }

    return true;
  }
};
