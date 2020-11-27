'''
0109. Convert Sorted List to Binary Search Tree

将链表转化为BST。

思路：
假设当前链表头为head
如果head->next == null,则
    head->left = null
    head->right = null
    return head

对每个链表，找到中点。方法如下：
表头设置一个dummy，并放指针pre
快慢指针从head开始。
while 快指针 != null and 快指针->next != null
    移动快指针两步
    移动慢指针和pre各一步

此时慢指针停留的位置就是中点
对中点左边的子链表，递归构建二叉搜索树。需要令pre->next=null，将中点左边的子链表尾部与大链表“切断”
对中点右边的子链表，递归构建二叉搜索树。slow->next就是中点右边的子链表表头


'''

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        # 如果是空链表
        if head == None:
            return head

        # 如果当前链表只有一个结点
        if head.next == None:
            head.left = None
            head.right = None
            return head
        
        # 找到链表中点
        dummy = ListNode(0, head)
        # 设置pre和快慢指针
        pre = dummy
        fast = head
        slow = head
        # 移动pre和快慢指针，直到slow停在中点
        while fast != None and fast.next != None:
            fast = fast.next.next
            slow = slow.next
            pre = pre.next
        
        # 将中点左边的子链表尾部与大链表“切断”
        pre.next = None
        # 中点左右的子链表递归构建BST
        new_head = TreeNode(slow.val, self.sortedListToBST(dummy.next), self.sortedListToBST(slow.next))
        new_head.left = self.sortedListToBST(dummy.next)
        new_head.right = self.sortedListToBST(slow.next)

        return new_head

        