/*
0031. Next Permutation

实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
必须 原地 修改，只允许使用额外常数空间。

思路：参考
https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-suan-fa-xiang-jie-si-lu-tui-dao-/
本题实际上在STL中有实现，就是用上述方法。函数为next_permutation

关键是要把下面的每一步理清楚：
1）先从后向前查找第一个相邻升序元素对a[i], a[j]，此时[j, end)是降序区间
2）在[j, end)，*从后向前*查找第一个满足a[i] < a[k]，将a[i]和[k]交换
3）此时[j, end)是逆序，将该区间逆置，使其升序
4）如果在步骤一找不到符合的相邻元素，说明整个数列是降序的，则直接将整个数列逆序
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
            return;

        // 查找从后向前第一个相邻升序对
        int i = nums.size() - 2, j = nums.size() - 1;
        while (i >= 0 && nums[i] >= nums[j]) {
            i--;
            j--;
        }
        // 从[j, end)，从后向前查找第一个满足nums[i] < nums[k]的 nums[k]
        if (i >= 0) {
            int k = nums.size() - 1;
            while (nums[i] >= nums[k])
                k--;
            // 交换nums[i], nums[k]
            swap(nums[i], nums[k]);
        }  
        // 此时[j, end)是降序，将其逆序
        reverse(nums.begin() + j, nums.end());
    }
};
