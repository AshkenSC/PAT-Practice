/*
剑指 Offer 57. 和为s的两个数字

输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。
如果有多对数字的和等于s，则输出任意一对即可。

思路：
一开始看到“有序”，觉得可能要用二分法。但是没想到思路。
后来参考题解，受到启发，想到用双指针。

其实思想类似于之前做的，在一个每行从小到大，每列从小到大的矩阵找一个数。
我们从二维数组左下角/右上角开始找。如果偏大，就做行移动；如果偏小，就做列移动。

这里，我们用双指针分别指向开头和结尾。
如果和偏大，就移动尾指针，让和变小；
如果和偏小，就移动头指针，让和变大。
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (nums[left] + nums[right] != target) {
            if (nums[left] + nums[right] > target) {
                --right;
            }
            else {
                ++left;
            }
        }

        return vector<int>({nums[left], nums[right]});
    }
};
