class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;
        ListNode* currentNode = head;

        // ���ζ�ȡ�����е���ֵ��ÿ��һ��ǰ���������2���ټ��ϵ�ǰλ�á�
        while (currentNode != nullptr) {
            result = result * 2 + (*currentNode).val;
            currentNode = (*currentNode).next;
        }

        return result;
    }
};