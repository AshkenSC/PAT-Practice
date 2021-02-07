/*
0105. Construct Binary Tree from Preorder and Inorder Traversal

给定一棵树先序遍历和中序遍历的数列，返回这棵树。

本题是对树的基本操作，应该熟悉。

个人思路：
用buildTree函数作为递归函数。每次当前结点的值是先序遍历的第一个元素。
然后根据该根结点划分先序遍历和中序遍历，各为左右两个子序列。
这样，左右子树又能分别根据上述获得的先序遍历和中序遍历子序列继续构造出来。

个人解法的大概思路是没有问题的，但是在具体执行时，由于试图传入具体的子数列，导致解答过于复杂。
应该参考官方解答，始终只传入原始的preorder和inorder两个数列，而左右子数列依靠index去直接在整体数列里规定界限。
*/

class Solution {
private:
    unordered_map<int, int> index;

public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        // 如果左 > 右，则退出递归
        // 注意别忘了！！！忘记好多次！！！
        if (preorder_left > preorder_right)
            return nullptr;

        // 先序遍历中当前结点的位置
        int preorder_pos = preorder_left;
        // 中序遍历中当前结点的位置
        int inorder_pos = index[preorder[preorder_left]];

        // 新建当前结点
        TreeNode* node = new TreeNode(preorder[preorder_left]);
        // 当前结点左子树的数目
        int leftSize = inorder_pos - inorder_left;
        // 进行递归
        node->left = build(preorder, inorder, preorder_left + 1, preorder_left + leftSize, inorder_left, inorder_pos - 1);
        node->right = build(preorder, inorder, preorder_left + leftSize + 1, preorder_right, inorder_pos + 1, inorder_right);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // 构造从结点取值到其在中序遍历索引的映射
        // 注意索引是inorder[i]
        for(int i = 0; i < n; i++)
            index[inorder[i]] = i;
        return build(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};


// wrong answer
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

        TreeNode *node = new TreeNode(preorder[0]);

        // 如果只剩单个结点
        if (preorder.size() < 2)
            return node;

        // 获取左右子树的中序遍历
        vector<int> left_inorder;
        vector<int> right_inorder;
        bool isLeft = true;
        for (int i = 1; i < inorder.size(); i++) {
            if (inorder[i] == node->val) {
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
        node->left = buildTree(left_preorder, left_inorder);
        node->right = buildTree(right_preorder, right_inorder);
        return node;
    }
};
