/*
0141. Linked List Cycle

给定一个链表，判断链表里是否有环路。
你是否能在O(1)时间里解决该问题？

思路：快慢双指针。
快指针一次走两步，慢指针一次走一步。如果存在环路，则必然相遇。
*/

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* fastPtr = head;
        ListNode* slowPtr = head;
        while (fastPtr && fastPtr->next) {
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
            if (fastPtr == slowPtr)
                return true;
        }
        return false;
    }
};