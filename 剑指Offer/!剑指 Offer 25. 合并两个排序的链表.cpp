/*
剑指 Offer 25. 合并两个排序的链表

输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

思路：有些生疏，不应该！是我想复杂了，想成归并排序之类的了，还在想是不是要递归啥的。
但这个已经是两个有序链表了。

*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        
        if (l1 != nullptr) {
            p->next = l1;
        }
        else {
            p->next = l2;
        }

        return dummy->next;
    }
};
