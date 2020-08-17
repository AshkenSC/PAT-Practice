/*
0160. Intersection of Two Linked Lists

写一个程序找到两个链表A，B的相交部分的起始点。

让两个指针分别从A，B头开始向后遍历，如果到了末尾，就从另一个链表头开始继续遍历，直到两个指针相遇为止。
这是因为，假设链表A自有部分长a，链表B自有部分长b，公共部分长c，那么这种情况下，两个指针都会走a+b+c的长度。
因此，如果他们存在公共部分，一定是在公共点起始处相遇。
*/

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        else {
            ListNode* pointerA = headA;
            ListNode* pointerB = headB;

            while (pointerA != pointerB) {
                if (pointerA != nullptr)
                    pointerA = pointerA->next;
                else
                    pointerA = headB;
                if (pointerB != nullptr)
                    pointerB = pointerB->next;
                else
                    pointerB = headA;
            }

            return pointerA;
        }
    }
};