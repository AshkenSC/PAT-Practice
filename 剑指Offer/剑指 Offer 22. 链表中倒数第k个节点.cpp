/*
剑指 Offer 22. 链表中倒数第k个节点

输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
*/

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        // 先移动fast
        for (int i = 0; i < k; ++i) {
            fast = fast->next;
        }
        // 再同时移动slow fast
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};