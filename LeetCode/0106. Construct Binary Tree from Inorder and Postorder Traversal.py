'''
0106. Construct Binary Tree from Inorder and Postorder Traversal

从中序和后序遍历构造二叉树。

思路：
（1）从后序的尾部确定根节点；
（2）在中序里定位根节点，从而划分左右子树；
（3）对左右子树，再分别在后序里找到其位置

为什么这题我想用Python？因为构造左右子树时，Python切片获得子列表很方便。

'''

from typing import List

# Definition for a binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def build(self, inorder: List[int], postorder: List[int]):
        pass
        

    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        # 递归终点
        if not postorder:
            return None

        # 后序最后一位是根节点
        root_val = postorder[-1]
        root_node = TreeNode(root_val)
        # 获取根节点在中序的位置，从而划分左右子树
        root_index = inorder.index(root_val)

        # 递归构造左右子树，注意list范围
        # 递归构造左子树
        left_tree = self.buildTree(inorder[0:root_index], postorder[0:root_index])
        # 递归构造右子树
        right_tree = self.buildTree(inorder[root_index+1:], postorder[root_index:-1])
        root_node.left = left_tree
        root_node.right = right_tree

        return root_node
