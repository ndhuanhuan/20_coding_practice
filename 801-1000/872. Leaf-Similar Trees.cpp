// https://zxi.mytechroad.com/blog/tree/leetcode-872-leaf-similar-trees/
class Solution {
public:
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leafs1;
    vector<int> leafs2;
    getLeafs(root1, leafs1);
    getLeafs(root2, leafs2);
    return leafs1 == leafs2;
  }
private:
  void getLeafs(TreeNode* root, vector<int>& leafs) {
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr)
      leafs.push_back(root->val);
    getLeafs(root->left, leafs);
    getLeafs(root->right, leafs);
  }
};
