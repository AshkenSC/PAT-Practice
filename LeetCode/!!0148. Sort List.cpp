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
        if (head == nullptr || head->next == nullptr)
            return head;
        
        // 通过快慢指针方法，快指针走2步，慢指针走1步，这样当快指针遍历完的时候，慢指针正好在中点
        ListNode* pmid;
        ListNode* mid = head;
        ListNode* trail = head;
        while(trail && trail->next) {
            pmid = mid;
            mid = mid->next;
            trail = trail->next->next;
        }
        pmid->next = nullptr;

        return twoWayMerge(sortList(head), sortList(mid));
    }

    ListNode* twoWayMerge(ListNode* l1, ListNode* l2) {
        ListNode header(-1);
        ListNode* p = &header;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        if (l1 == nullptr)
            p->next = l2;
        else
            p->next = l1;
        
        return header.next;
    }
};