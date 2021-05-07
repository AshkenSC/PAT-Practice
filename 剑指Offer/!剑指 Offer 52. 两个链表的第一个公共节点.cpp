/*
剑指 Offer 52. 两个链表的第一个公共节点

输入两个链表，找出它们的第一个公共节点。

思路：用两个指针分别走过两个链表。如果走到尽头了，就从另一个链表的头开始继续走。
这样一定会在交点处相遇。

假设两个链表非公共部分长度分别为a, b，公共部分长度为x。
则按上述走法，两个指针分别都走过了a + b + x长度，减去公共部分长度，都走了a + b。
所以那么一定会在交点相遇。

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            if (pA != nullptr) {
                pA = pA->next;
            }
            else {
                pA = headB;
            }

            if (pB != nullptr) {
                pB = pB->next;
            }
            else {
                pB = headA;
            }
        }

        return pA;
    }
};
