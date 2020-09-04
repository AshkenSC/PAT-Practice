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
        ListNode* newHead;
        ListNode* pre;
        ListNode* current;
        if (head == nullptr || head->next == nullptr)
            return head;
        else {
            newHead = head;
            current = head->next;
            pre = current;
            // 这一步要在前两步之后进行，否则前两步中的head的next就被这一步所修改了
            newHead->next = nullptr;
            while (current != nullptr) {
                pre = current->next;
                current->next = newHead;
                newHead = current;
                current = pre;
            }
            return newHead;
        }
    }
};