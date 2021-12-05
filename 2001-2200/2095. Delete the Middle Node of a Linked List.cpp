
class Solution {
public:
  ListNode* deleteMiddle(ListNode* head) {
    ListNode dummy(0, head);
    ListNode* prev = &dummy;
    ListNode* fast = head;
    // prev points to the previous node of the middle one.
    while (fast && fast->next) {
      prev = prev->next;
      fast = fast->next->next;
    }    
    prev->next = prev->next->next;
    return dummy.next;
  }
};
