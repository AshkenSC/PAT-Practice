/*
0023. Merge k Sorted Lists

给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。

思路：归并排序经典题。参考官方解答。

*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if (!a || !b) {
            return a ? a : b;
        }
        ListNode head;
        ListNode *tail = &head;
        ListNode *aPtr = a, *bPtr = b;
        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr;
                aPtr = aPtr->next;
            }
            else {
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            tail = tail->next;
        }

        // 归并完了，a或者b会剩下一部分有序的，将他们放到归并结果尾部。
        tail->next = (aPtr ? aPtr : bPtr);

        return head.next;
    }

    ListNode* merge(vector<ListNode*>& lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        if (start > end) {
            return nullptr;
        }

        int mid = (start + end) / 2;
        return mergeTwoLists(merge(lists, start, mid), merge(lists, mid + 1, end));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};
