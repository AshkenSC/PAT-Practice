/*
0025. Reverse Nodes in k-Group

给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。
如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

思路：参考官方解答。花了很久才熟悉。

*/

class Solution {
public:
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }

        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;
        ListNode* tail = pre;

        while (head) {
            // 检查下面要操作的链表长度够k吗
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }

            ListNode* nex = tail->next;
            pair<ListNode*, ListNode*> res = myReverse(head, tail);
            head = res.first;
            tail = res.second;
            // 将子链表接回原链表  
            pre->next = head;
            tail->next = nex;
            // 调整pre, head位置，准备下一段反转
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }
};
