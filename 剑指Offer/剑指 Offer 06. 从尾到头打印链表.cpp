/*
剑指 Offer 06. 从尾到头打印链表

输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

思路：先逆置，再输出。

*/

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        if (head == nullptr) {
            return res;
        }

        ListNode *pre = nullptr, *p = head, *next = head->next;
        while (next != nullptr) {
            p->next = pre;
            pre = p;
            p = next;
            next = next->next;
        }
        p->next = pre;

        while (p != nullptr) {
            res.push_back(p->val);
            p = p->next;
        }

        return res;
    }
};
