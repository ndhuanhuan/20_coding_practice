// https://zxi.mytechroad.com/blog/tree/leetcode-2096-step-by-step-directions-from-a-binary-tree-node-to-another/
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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startpath;
        string destpath;
        buildpath(root, startValue, startpath);
        buildpath(root, destValue, destpath);
        
        while(!startpath.empty() && !destpath.empty() && startpath.back() == destpath.back()) {
            startpath.pop_back();
            destpath.pop_back();
        }
        
        string res;
        int startLen = startpath.length();
        res.append(startLen, 'U');
        reverse(destpath.begin(), destpath.end());
        res += destpath;
        
        return res;
    }
    
    
    bool buildpath(TreeNode* root, int value, string& path) {
        if(!root) return false;
        if(root->val == value) return true;
        if(buildpath(root->left, value, path) == true) {
            path.push_back('L');
            return true;
        } else if(buildpath(root->right, value, path) == true) {
            path.push_back('R');
            return true;
        }
        
        return false;
    }
};
