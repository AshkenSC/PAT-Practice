/*
0581. Shortest Unsorted Continuous Subarray

给定一个整数数组，找到里面一个子数组，把这个子数组排序以后整个数组就变成升序有序数组了。
你需要找到这个子数组的最短长度。

思路：
1）从左往右遍历，记录遍历过的部分的最大值。如果当前遍历到的元素比最大值要小，则该元素需要重排。记录该位置为high
2）从右往左遍历，记录遍历过的部分的最小值。如果当前遍历到的元素比最小值大，则该元素需要重排。记录该位置为low
3）如果high==low（记得之前需要初始化为相同值），则数组整体有序。否则返回high-low+1
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int maxCache = nums[0];
        int minCache = nums[nums.size() - 1];
        int lowPos = -1, highPos  = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < maxCache)
                highPos = i;
            else
                maxCache = nums[i];
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] > minCache)
                lowPos = i;
            else
                minCache = nums[i];
        }
        if (highPos == lowPos)
            return 0;
        else
            return highPos - lowPos + 1;
    }
};
