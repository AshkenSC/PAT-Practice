/*
0108. Convert Sorted Array to Binary Search Tree

将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

思路：分治法。
每次只选取数组中间的元素创建新的根节点，然后对该根结点左右子数组分而治之，以此类推。
*/

class Solution {
public:

    TreeNode* build(vector<int>& nums, int left, int right) {
        if (left > right)
            return NULL;

        int mid = (left + right) / 2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, left, mid - 1);
        root->right = build(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
};