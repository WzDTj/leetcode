#include "../structures/tree_node.cpp"
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  // 递归

  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> answer;
    traversal(answer, root);
    return answer;
  }

  // 迭代

  // vector<int> inorderTraversal(TreeNode *root) {
  //   vector<int> answer;
  //
  //   stack<TreeNode *> stack;
  //
  //   TreeNode *current = root;
  //
  //   while (current != nullptr || !stack.empty()) {
  //     // 不断访问左节点并入栈
  //     while (current != nullptr) {
  //       stack.push(current);
  //       current = current->left;
  //     }
  //
  //     // 访问并记录元素
  //     current = stack.top();
  //     stack.pop();
  //     answer.push_back(current->val);
  //
  //     // 访问右节点
  //     current = current->right;
  //   }
  //
  //   return answer;
  // }

private:
  void traversal(vector<int> &answer, TreeNode *root) {
    if (root == nullptr)
      return;

    traversal(answer, root->left);
    answer.push_back(root->val);
    traversal(answer, root->right);
  }
};
