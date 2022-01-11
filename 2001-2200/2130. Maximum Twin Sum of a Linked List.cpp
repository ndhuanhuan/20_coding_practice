class Solution {
public:
    ListNode* reverseList(ListNode* cur, ListNode* prev = nullptr) {
        while (cur != nullptr) {
            swap(cur->next, prev);
            swap(prev != nullptr ? prev->next : prev, cur);
        }
        return prev;
    }    
    int pairSum(ListNode* head) {
        int res = 0;
        auto slow = head, fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = reverseList(slow);
        while (slow != nullptr) {
            res = max(res, slow->val + head->val);
            slow = slow->next;
            head = head->next;
        }
        return res;
    }
};
