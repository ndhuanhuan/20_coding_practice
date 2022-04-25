/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        const int n = getLen(head);
        h = head;
        return buildBST(0, n -1);
    }
    
    TreeNode* buildBST(int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right -left) / 2;
        TreeNode* leftNode = buildBST(left, mid-1);
        
        TreeNode* root = new TreeNode(h->val);
        h = h->next;
        
        root->left = leftNode;
        root->right = buildBST(mid + 1, right);
        
        return root;
    }

private:
    ListNode* h;
    
    int getLen(ListNode* head) {
        int cnt = 0;
        while(head != nullptr) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
};

