/*
0203. Remove Linked List Elements

删除链表中等于给定值 val 的所有节点.

思路：主要是要考虑删除头结点以及连续删除头结点的情况。
方法是设置一个哨兵头结点在前面，让头结点得以和其他结点同等对待。

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(val + 1, head);
        ListNode* p = dummyHead;

        while (p->next != nullptr) {
            if (p->next->val == val) {
                p->next = p->next->next;
            }
            else {
                p = p->next;
            }
        }

        return dummyHead->next;
    }
};