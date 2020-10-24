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
 
    TreeNode *answer=nullptr;
    void inorder(TreeNode *root,TreeNode *u,int &find_level,int curr_level){
        if(!root || answer) return;
        inorder(root->left,u,find_level,curr_level+1);
        if(root==u) find_level=curr_level;
        else if(curr_level==find_level) answer=root;
        inorder(root->right,u,find_level,curr_level+1);
    }
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        if(!root) nullptr;
        int find_level=-1;
        inorder(root,u,find_level,0);
        return answer;
    }
};
