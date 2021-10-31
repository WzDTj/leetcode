#include "../structures/tree_node.cpp"
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (!root)
      return {};

    queue<TreeNode *> queue({root});

    vector<vector<int>> answer;

    while (!queue.empty()) {
      vector<int> tmp;
      int count = queue.size();
      while (count--) {
        TreeNode *front = queue.front();
        tmp.push_back(front->val);
        queue.pop();

        if (front->left)
          queue.push(front->left);
        if (front->right)
          queue.push(front->right);
      }

      answer.push_back(tmp);
    }

    return answer;
  }
};
