/*
0082. Remove Duplicates from Sorted List II

给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

思路：
设置3个指针pre, start, end，分别指向连续重复数字的起点前一位、起点和终点。
设置一个dummyHead，其next为head。
pre从dummyHead开始。
start和end都从head开始。

当end->next不为空时，执行循环：
如果end->next != null && end->next->value != end->value，则
    pre, start, end同时向后移动
如果end->next != null && end->next->value == end->value，则
    循环执行end = end->next，直到end->next == null || end->value ！= end->next->value。
    删除从start到end的所有元素：
        pre->next = end->next
    end = end->next
    start = end

注意处理一个链表元素全都相同的情况，这时返回空链表。
*/

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;

        // 设置一个dummyHead
        ListNode *dummyHead = new ListNode(head->val - 1);
        dummyHead->next = head;

        // 设置pre，start，end三指针
        ListNode *pre = dummyHead;
        ListNode *start = head;
        ListNode *end = head;

        // 删除重复元素
        while (end && end->next != nullptr) {
            if (end->next != nullptr && end->next->val != end->val) {
                start = start->next;
                end = end->next;
                pre = pre->next;
            }
            else if (end->next != nullptr && end->next->val == end->val) {
                // 将end定位到最后一个重复元素
                while (true) {
                    end = end->next;
                    if (end->next == nullptr || end->val != end->next->val)
                        break;
                }
                // 删除从start到end的所有元素
                pre->next = end->next;
                // 将start和end设到重复元素下一位
                end = end->next;
                start = end;
            }
        }

        return dummyHead->next;
    }
};