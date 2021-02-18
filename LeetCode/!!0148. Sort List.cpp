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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *preMid;
        ListNode *mid = head;
        ListNode *p = head;
        while (p && p->next) {
            preMid = mid;
            mid = mid->next;
            p = p->next->next;
        }
        preMid->next = nullptr;

        return twoWayMerge(sortList(head), sortList(mid));
    }

    ListNode* twoWayMerge(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0);
        ListNode *p = head;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        
        p->next = l1 == nullptr ? l2 : l1;

        return head->next;
    }
};

