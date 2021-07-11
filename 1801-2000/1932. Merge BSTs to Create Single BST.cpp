// https://leetcode.com/problems/merge-bsts-to-create-single-bst/discuss/1330387/Just-do-what-it-says
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
    unordered_set<int> unique_vals;
    unordered_map<int, TreeNode*> roots;
    vector<TreeNode*> leaves;
    void addLeaves(TreeNode* r, bool root = true) {
        if (r != nullptr) {
            unique_vals.insert(r->val);
            if (!root && r->left == r->right && roots.count(r->val)) // r->left == r->right means both left and right are nullptr
                leaves.push_back(r);
            addLeaves(r->left, false);
            addLeaves(r->right, false);
        }
    }    
    int validNodes(TreeNode* r, int min_left = INT_MIN, int max_right = INT_MAX) {
        if (r == nullptr || r->val <= min_left || r->val >= max_right) 
            return 0;
        return 1 + validNodes(r->left, min_left, r->val) + validNodes(r->right, r->val, max_right);
    } 
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        for (auto &tree : trees)
            roots[tree->val] = tree;
        for (auto &tree : trees)
             addLeaves(tree);
        for (auto leaf : leaves) {
            auto it = roots.find(leaf->val);
            if (it == end(roots)) 
                return nullptr;
            leaf->left = it->second->left;
            leaf->right = it->second->right;
            roots.erase(it);
        }
        return roots.size() == 1 && validNodes(begin(roots)->second) == unique_vals.size() ? begin(roots)->second : nullptr;
    }
};
