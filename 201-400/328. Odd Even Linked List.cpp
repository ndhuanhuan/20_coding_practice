//http://www.cnblogs.com/grandyang/p/5138936.html
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *odd = head, *even = head->next, *even_head = even;
        while (even && even->next) {
            odd = odd->next = even->next;
            even = even->next = odd->next;
        }
        odd->next = even_head;
        return head;
    }
};
