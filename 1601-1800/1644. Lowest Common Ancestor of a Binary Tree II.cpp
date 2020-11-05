/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        pair<TreeNode*, bool> res = hp(root, p, q);
        return res.second ? res.first : nullptr;
    }
    pair<TreeNode*, bool> hp(TreeNode* r, TreeNode* p, TreeNode* q) {
        if (!r) return {nullptr, false};
        pair<TreeNode*, bool> left = hp(r->left, p, q), right = hp(r->right, p, q);
        if (left.first && right.first)
            return {r, true};
        if (r == p || r == q)
            return {r, left.first || right.first};
        return left.first ? left : right;
    }
};
