#include "../structures/tree_node.cpp"
#include <stack>

using namespace std;

class Solution {
public:
  // 递归

  bool isSymmetric(TreeNode *root) { return valid(root->left, root->right); }

  // 迭代

  // bool isSymmetric(TreeNode *root) {
  //   stack<TreeNode *> stack;
  //
  //   stack.push(root->left);
  //   stack.push(root->right);
  //
  //   while (!stack.empty()) {
  //     TreeNode *right = stack.top();
  //     stack.pop();
  //     TreeNode *left = stack.top();
  //     stack.pop();
  //
  //     if (left == nullptr && right == nullptr)
  //       continue;
  //
  //     if ((left == nullptr || right == nullptr) || (left->val != right->val))
  //       return false;
  //
  //     stack.push(left->left);
  //     stack.push(right->right);
  //
  //     stack.push(left->right);
  //     stack.push(right->left);
  //   }
  //
  //   return true;
  // }

private:
  bool valid(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right == nullptr)
      return true;
    else if (left == nullptr || right == nullptr)
      return false;
    else
      return left->val == right->val && valid(left->left, right->right) &&
             valid(left->right, right->left);
  }
};
