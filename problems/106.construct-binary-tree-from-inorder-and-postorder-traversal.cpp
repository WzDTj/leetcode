#include "../structures/tree_node.cpp"
#include <vector>

using namespace std;

class Solution {
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int n = inorder.size();
    if (!n)
      return nullptr;

    int value = postorder[n - 1];
    vector<int>::iterator root_it = find(inorder.begin(), inorder.end(), value);
    vector<int> inorder_left = vector<int>(inorder.begin(), root_it);
    vector<int> inorder_right = vector<int>(root_it + 1, inorder.end());

    vector<int> postorder_left =
        vector<int>(postorder.begin(), postorder.begin() + inorder_left.size());
    vector<int> postorder_right = vector<int>(
        postorder.begin() + postorder_left.size(), postorder.end() - 1);

    return new TreeNode(value, buildTree(inorder_left, postorder_left),
                        buildTree(inorder_right, postorder_right));
  }
};
