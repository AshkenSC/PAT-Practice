/*
剑指 Offer 33. 二叉搜索树的后序遍历序列

输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同

思路：分治递归，关键点是如何逐层划分子数组。

参考：
https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/solution/mian-shi-ti-33-er-cha-sou-suo-shu-de-hou-xu-bian-6/
*/

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return recur(postorder, 0, postorder.size() - 1);
    }

    bool recur(vector<int>& postorder, int i, int j) {
        if (i >= j) return true;

        // 划分左右子树
        //（就是这一点一开始没想清楚，一开始我知道要用递归，但不知道如何层层划分）
        int p = i;
        while (postorder[p] < postorder[j]) ++p;
        int m = p;
        while (postorder[p] > postorder[j]) ++p;

        // 要同时满足：当前树是否正确（p==j），左右子树经递归验证都通过
        // 注意j-1不是j，因为当前树的根节点就是j
        return p == j && recur(postorder, i, m - 1) && recur(postorder, m, j - 1);
    }
};
