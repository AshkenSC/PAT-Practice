/*
0088. Merge Sorted Array

给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

思路：
参考官方解答3，由于nums1前面存了数，因此考虑将数组从后向前插入元素。

*/

#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = nums1.size() - 1;   // 工作在nums1尾部，插入新元素
        int i = m - 1;              // 从nums1有数的部位尾部开始向前
        int j = n - 1;              // 从nums2尾部向前

        // 将数组从后向前插入
        while (p >= 0 && i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[p] = nums1[i];
                i--;
            }
            else {
                nums1[p] = nums2[j];
                j--;
            }
            p--;
        }

        // 将两个原数组中剩下的部分拷贝入结果数组
        // 两个while只有一个会执行
        while (i >= 0 && p >= 0) {
            nums1[p] = nums1[i];
            p--;
            i--;
        }
        while (j >= 0 && p >= 0) {
            nums1[p] = nums2[j];
            p--;
            j--;
        }

    }
};