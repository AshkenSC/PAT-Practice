/*
24. Swap Nodes in Pairs

给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

思路：1）递归。太牛逼啦！
2）迭代，用传统方法遍历做。

*/


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 当链表长度小于2时
        if (head == nullptr || head->next == nullptr)
            return head;
        // 当链表长度大于等于2时
        ListNode *next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
};