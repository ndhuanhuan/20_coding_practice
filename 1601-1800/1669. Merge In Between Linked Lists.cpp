// https://zxi.mytechroad.com/blog/list/leetcode-1669-merge-in-between-linked-lists/
class Solution {
public:
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode dummy(0, list1);
    ListNode* prev_a = &dummy;
    for (int i = 0; i < a; ++i) prev_a = prev_a->next;
    ListNode* node_b = prev_a->next;
    for (int i = a; i <= b; ++i) node_b = node_b->next;
    ListNode* tail2 = list2;
    while (tail2->next) tail2 = tail2->next;
    
    prev_a->next = list2;    
    tail2->next = node_b;
    return list1;
  }
};
