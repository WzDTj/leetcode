#include "../structures/tree_node.cpp"
#include <string>

using namespace std;

class Solution {
public:
  string tree2str(TreeNode *root) {
    if (root == nullptr) {
      return "";
    }

    string answer = to_string(root->val);

    if (root->left != nullptr || root->right != nullptr) {
      answer += "(" + tree2str(root->left) + ")";
    }

    if (root->right != nullptr) {
      answer += "(" + tree2str(root->right) + ")";
    }

    return answer;
  }
};
