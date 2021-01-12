// https://zxi.mytechroad.com/blog/list/leetcode-1721-swapping-nodes-in-a-linked-list/
class Solution {
public:
  ListNode* swapNodes(ListNode* head, int k) {
    int l = 0;
    ListNode* cur = head;    
    while (cur) { cur = cur->next; ++l; }    
    
    cur = head;
    ListNode* n1 = nullptr;
    ListNode* n2 = nullptr;
    for (int i = 1; i <= l; ++i, cur = cur->next) {
      if (i == k) n1 = cur;
      if (i == l - k + 1) n2 = cur;
    }
    swap(n1->val, n2->val);
    return head;
  }
};
