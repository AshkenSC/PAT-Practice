/*
0206. Reverse Linked List

逆置链表，采用头插法。
注意输入数据可能是nullptr
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* newHead = head;
        ListNode* currentNode = head->next;
        ListNode* newNode;
        newHead->next = nullptr;
        while (currentNode != nullptr) {
            newNode = currentNode->next;
            currentNode->next = newHead;
            newHead = currentNode;
            currentNode = newNode;
        }
        return newHead;
    }
};