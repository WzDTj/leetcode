#include "../structures/tree_node.cpp"
#include <stack>

using namespace std;

class Solution {
public:
  // 迭代 - 先序遍历

  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) {
      return true;
    } else if (q == nullptr || p == nullptr) {
      return false;
    }

    stack<TreeNode *> p_stack({p});
    stack<TreeNode *> q_stack({q});

    while (!p_stack.empty() && !q_stack.empty()) {
      TreeNode *p_current = p_stack.top();
      TreeNode *q_current = q_stack.top();
      p_stack.pop();
      q_stack.pop();

      if (p_current->val != q_current->val) {
        return false;
      }

      if (p_current->left != nullptr && q_current->left != nullptr) {
        p_stack.push(p_current->left);
        q_stack.push(q_current->left);
      } else if (p_current->left != q_current->left) {
        return false;
      }

      if (p_current->right != nullptr && q_current->right != nullptr) {
        p_stack.push(p_current->right);
        q_stack.push(q_current->right);
      } else if (p_current->right != q_current->right) {
        return false;
      }
    }

    return true;
  }
  // 递归

  // bool isSameTree(TreeNode *p, TreeNode *q) {
  //   if (p == nullptr && q == nullptr) {
  //     return true;
  //   } else if (p == nullptr || q == nullptr) {
  //     return false;
  //   } else if (p->val != q->val) {
  //     return false;
  //   } else {
  //     return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  //   }
  // }
};
