# 21. Merge Two Sorted Lists
'''
用两个指针分别指向l1, l2，逐个比较元素，将小的放入output。最后其中一个链表剩下的部分再接到output上。
需要考虑l1,l2为空的情况。
'''


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        # 如果l1, l2有一个是空链表，直接输出结果
        if l1 is None:
            return l2
        elif l2 is None:
            return l1

        # 确定合并链表的头结点
        if l1.val < l2.val:
            output = l1
            index1 = l1.next
            index2 = l2
        else:
            output = l2
            index1 = l1
            index2 = l2.next

        # 遍历两个链表并比较、插入output
        output_pointer = output
        while index1 is not None and index2 is not None:
            if index1.val < index2.val:
                output_pointer.next = index1
                index1 = index1.next
            else:
                output_pointer.next = index2
                index2 = index2.next
            output_pointer = output_pointer.next

        # 将剩下的链表接到output上
        if index1 is not None:
            output_pointer.next = index1
        else:
            output_pointer.next = index2

        return output

# test
# sol = Solution()
# l1 = ListNode()
# ans = sol.mergeTwoLists()
# print(ans)