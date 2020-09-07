/*
0105. Construct Binary Tree from Preorder and Inorder Traversal

给定一棵树先序遍历和中序遍历的数列，返回这棵树。

个人思路：
用buildTree函数作为递归函数。每次当前结点的值是先序遍历的第一个元素。
然后根据该根结点划分先序遍历和中序遍历，各为左右两个子序列。
这样，左右子树又能分别根据上述获得的先序遍历和中序遍历子序列继续构造出来。

*/

// compile error
class Solution {
public:
    bool is_element_in_vector(vector<int> v,int element){
        vector<int>::iterator it;
        it=find(v.begin(),v.end(),element);
        if (it!=v.end()){
            return true;
        }
        else{
            return false;
        }
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 如果是空树
        if (preorder.size() < 1)
            return nullptr;

        TreeNode node = TreeNode();
        TreeNode* nodePtr = &node;
        node.val = preorder[0];

        // 如果只剩单个结点
        if (preorder.size() < 2)
            return nodePtr;

        // 获取左右子树的中序遍历
        vector<int> left_inorder;
        vector<int> right_inorder;
        bool isLeft = true;
        for (int i = 1; i < inorder.size(); i++) {
            if (inorder[i] == node.val) {
                isLeft = false;
                continue;
            }
            if (isLeft)
                left_inorder.push_back(inorder[i]);
            else
                right_inorder.push_back(inorder[i]);
        }

        // 获取左右子树的先序遍历
        vector<int> left_preorder;
        vector<int> right_preorder;
        isLeft = true;
        for (int i = 1; i < preorder.size(); i++) {
            if (is_element_in_vector(left_inorder, preorder[i]))
                isLeft = false;
            if (isLeft)
                left_preorder.push_back(preorder[i]);
            else
                right_preorder.push_back(preorder[i]);
        }

        // 递归
        node.left = buildTree(left_preorder, left_inorder);
        node.right = buildTree(right_preorder, right_inorder);
        return nodePtr;
    }
};