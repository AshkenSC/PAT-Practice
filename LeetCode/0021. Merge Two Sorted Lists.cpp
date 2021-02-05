/*
0021. Merge Two Sorted Lists

将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        while (l1 != nullptr && l2 != nullptr) {
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

        // 拼接剩下的部分
        if (l1 != nullptr) {
            p->next = l1;
        }
        if (l2 != nullptr) {
            p->next = l2;
        }
        
        return dummy->next;
    }
};