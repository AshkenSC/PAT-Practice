class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;
        ListNode* currentNode = head;

        // 依次读取链表中的数值，每读一次前将结果乘以2，再加上当前位置。
        while (currentNode != nullptr) {
            result = result * 2 + (*currentNode).val;
            currentNode = (*currentNode).next;
        }

        return result;
    }
};