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
    int equalToDescendants(TreeNode* root) {
        int res = 0;
        sum(root, res);
        return res;
    }
private:
    long sum(TreeNode* root, int& res)
    {
        if(root == nullptr)
        {
            return 0;
        }
        long left = sum(root->left, res);
        long right = sum(root->right, res);
        if(left + right == root->val)
        {
            res++;
        }
        return left + right + root->val;
    }
};
