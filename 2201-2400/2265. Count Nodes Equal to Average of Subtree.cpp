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
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
    
    // sum, number of nodes
    vector<int> helper(TreeNode* root, int& res) {
        if(!root) return {0, 0};
        
        auto left = helper(root->left, res);
        auto right = helper(root->right, res);
        
        int total_nodes = left[1] + right[1] + 1;
        int sum = left[0] + right[0] + root->val;
        
        if(root->val == sum / total_nodes) {
            res++;
        }
        
        return {sum, total_nodes};
    }
};
