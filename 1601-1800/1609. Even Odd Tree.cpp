// https://zxi.mytechroad.com/blog/uncategorized/leetcode-1609-even-odd-tree/
class Solution {
public:
  bool isEvenOddTree(TreeNode* root) {
    vector<int> vals;
    function<bool(TreeNode*, int)> dfs = [&](TreeNode* root, int d) {
      if (!root) return true;
      if (vals.size() <= d)
        vals.push_back(d % 2 == 0 ? -1 : INT_MAX);
      int& val = vals[d]; // get address, tricky part
      if (d % 2 == 0)
        if (root->val % 2 == 0 || root->val <= val) return false;
      if (d % 2 == 1)
        if (root->val % 2 == 1 || root->val >= val) return false;
      val = root->val;
      return dfs(root->left, d + 1) && dfs(root->right, d + 1);
    };
    return dfs(root, 0);
  }
};
