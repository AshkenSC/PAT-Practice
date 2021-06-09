/*
剑指 Offer 18. 删除链表的节点

给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
返回删除后的链表的头节点。

思路：
一开始采用的是，不真正删除当前节点，而是将next的值赋值给当前点，然后删除next。
但是这样搞不好处理删除尾巴节点的情况。

于是改为，指针找到待删除节点前一个就停下。这样可以方便处理。

*/

// 方法1：单指针
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        // 特殊情况 删除头节点
        if (head->val == val) {
            return head->next;
        }
        ListNode *p = head;
        while (p->next->val != val) {
            p = p->next;
        }
        p->next = p->next->next;

        return head;
    }
};

// 方法2：双指针
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val) {
            return head->next;
        }

        ListNode *p = head;
        ListNode *pre = nullptr;
        while (p->val != val) {
            pre = p;
            p = p->next;
        }
        pre->next = p->next;

        return head;      
    }
};

