// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/discuss/957854/C%2B%2B-unordered_set
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        unordered_set<TreeNode*> ns(begin(nodes), end(nodes));
        traverse(root, ns);
        return res;
    }
    
    TreeNode *res = nullptr;
    int traverse(TreeNode* r, unordered_set<TreeNode*> &ns) {
        int match = r == nullptr ? 0 :
            ns.count(r) + traverse(r->left, ns) + traverse(r->right, ns);
        if (match == ns.size() && res == nullptr)
            res = r;
        return match;
    }  
    
};
