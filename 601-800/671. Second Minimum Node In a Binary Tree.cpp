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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        deque<TreeNode*> q;
        q.push_back(root);
        // Smallest value
        int s1 = root->val;
        // Sencond smallest value
        int s2 = -1;
        bool found = false;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop_front();
            // Keep updating second smallest value
            if(cur->val > s1 && (s2 == -1 || cur->val < s2)) {
                s2 = cur->val;
                found = true;
                // No need to add it's children into queue
                continue; 
            }
            
            if(cur->left) q.push_back(cur->left);
            if(cur->right) q.push_back(cur->right);
        }
        
        return s2;
    }
};

//http://www.cnblogs.com/grandyang/p/7590156.html
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        int first = root->val, second = INT_MAX;
        helper(root, first, second);
        return (second == first || second == INT_MAX) ? -1 : second;
    }
    void helper(TreeNode* node, int& first, int& second) {
        if (!node) return;
        if (node->val != first && node->val < second) {
            second = node->val;
        }
        helper(node->left, first, second);
        helper(node->right, first, second);
    }
};
