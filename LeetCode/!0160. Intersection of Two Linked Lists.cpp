/*
0160. Intersection of Two Linked Lists

写一个程序找到两个链表A，B的相交部分的起始点。

让两个指针分别从A，B头开始向后遍历，如果到了末尾，就从另一个链表头开始继续遍历，直到两个指针相遇为止。
这是因为，假设链表A自有部分长a，链表B自有部分长b，公共部分长c，那么这种情况下，两个指针都会走a+b+c的长度。
因此，如果他们存在公共部分，一定是在公共点起始处相遇。

参考:
https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/jiao-ni-yong-lang-man-de-fang-shi-zhao-dao-liang-2/
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }

        ListNode *pA = headA;
        ListNode *pB = headB;
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