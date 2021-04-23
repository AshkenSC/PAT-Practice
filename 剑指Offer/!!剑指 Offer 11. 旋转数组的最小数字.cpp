/*
剑指 Offer 11. 旋转数组的最小数字

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。

思路：二分法，关键难点是理解，当右端点==中点的值时，为何可以right--来缩小范围。

参考：https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/solution/mian-shi-ti-11-xuan-zhuan-shu-zu-de-zui-xiao-shu-3/
*/

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size() - 1;
        int mid = left + (right - left) / 2;

        while (left < right) {
            mid = left + (right - left) / 2;
            if (numbers[mid] == numbers[right]) {
                right -= 1;
            }
            else if (numbers[mid] < numbers[right]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return numbers[left];
    }
};
