/*
0083. Remove Duplicates from Sorted List

给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

思路：
设置一个空的头结点，方便操作；
设置两个指针，pre和current。只要两个指向的元素相等，就删除current指向结点。
*/

#include <vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;

        // 设置一个空头结点
        ListNode* dummyHead = new ListNode(head->val - 1);
        dummyHead->next = head;

        ListNode *pre = dummyHead;
        ListNode *current = head;

        while (current != nullptr) {
            if (current->val == pre->val) {
                ListNode *delNode = current;
                // current直接指向下一个结点
                current = current->next;
                // pre的next也改为下一个结点
                pre->next = current;
                // 删除重复结点
                delete delNode;
            }
            else {
                current = current->next;
                pre = pre->next;
            }
        }
        return dummyHead->next;
    }
};