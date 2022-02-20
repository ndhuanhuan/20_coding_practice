class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* resHead = dummy;
        if(!head) return head;
        ListNode* cur = head;
        cur = cur->next;
        int sum = 0;
        while(cur) {
            if(cur->val != 0) {
                sum += cur->val;
            } else {
                resHead->next = new ListNode(sum);
                resHead = resHead->next;
                sum = 0;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};
