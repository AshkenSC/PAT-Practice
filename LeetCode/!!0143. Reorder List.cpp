/*
0143. Reorder List

给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

思路：
综合了多个技巧。好题！

1）首先用快慢指针，找到链表中点；
2）然后将后半部分就地逆置；
3）最后将两个一半的链表交错拼接结点。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return;
        }

        // 1. 找到链表终点
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        // 此时slow->next是链表后半段的头结点
        // slow作为前半段的终点，mid作为后半段的起点（逆置后的终点）
        // 2. 就地逆置后半段
        ListNode *mid = slow->next;
        slow->next = nullptr;
        ListNode *p = mid;
        ListNode *prior = nullptr;
        ListNode *next = p->next;
        while (next) {
            p->next = prior;
            prior = p;
            p = next;
            next = next->next;
        }
        p->next = prior;    // 此时p是逆置后的后半链表的起点

        // 3. 交错拼接两个子链表
        ListNode *q = head;
        ListNode *qNext = q->next;
        ListNode *pNext = p->next;
        while (pNext) {
            q->next = p;
            p->next = qNext;
            q = qNext;
            qNext = qNext->next;
            p = pNext;
            pNext = pNext->next;
        }
        q->next = p;
        p->next = qNext;
    }
};