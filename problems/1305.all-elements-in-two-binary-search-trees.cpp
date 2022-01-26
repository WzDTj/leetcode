#include "../structures/tree_node.cpp"
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    vector<int> v1, v2;

    traversal(root1, v1);
    traversal(root2, v2);

    int n1 = v1.size(), n2 = v2.size();
    vector<int> answer;

    int i1 = 0, i2 = 0;
    while (i1 < n1 || i2 < n2) {
      if (i1 < n1) {
        answer.push_back(v2[i2++]);
      } else if (i2 == n2 || v1[i1] < v2[i2]) {
        answer.push_back(v1[i1++]);
      } else {
        answer.push_back(v2[i2++]);
      }
    }

    return answer;
  }

private:
  void traversal(TreeNode *root, vector<int> &v) {
    if (root == nullptr) {
      return;
    }

    traversal(root->left, v);

    v.push_back(root->val);

    traversal(root->right, v);
  }
};
