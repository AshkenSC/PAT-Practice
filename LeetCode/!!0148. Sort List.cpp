/*
0148. Sort List.cpp

在O(n logn)时间复杂度和常数空间复杂度内对链表排序

思路：归并排序
参考https://leetcode-cn.com/problems/sort-list/solution/kuai-man-zhi-zhen-er-lu-gui-bing-c-by-jiangtianyu0/
先用快慢指针的方法找到链表的中点
再用归并排序对链表排序
*/


struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
 
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        ListNode *head = new ListNode(-1);
        ListNode *p = head;

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
            }
            else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }

        if (p1 != nullptr) {
            p->next = p1;
        }
        else {
            p->next = p2;
        }

        return head->next;
    }

    ListNode* sortList(ListNode* head) {
        // 注意两个判断条件都不能丢
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // 使用快慢双指针找到链表中间结点
        ListNode *fast = head, *slow = head, *preMid = head;
        while (fast != nullptr && fast->next != nullptr) {
            preMid = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // 注意别忘记断链
        preMid->next = nullptr;

        return merge(sortList(head), sortList(slow));
    }
};
