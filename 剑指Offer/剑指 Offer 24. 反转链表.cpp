/*
剑指 Offer 24. 反转链表

定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 特殊情况，链表长度为0或者1
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *pre = nullptr, *p = head, *nex = head->next;
        while (nex != nullptr) {
            p->next = pre;
            pre = p;
            p = nex;
            nex = nex->next;
        }
        p->next = pre;

        return p;
    }
};
