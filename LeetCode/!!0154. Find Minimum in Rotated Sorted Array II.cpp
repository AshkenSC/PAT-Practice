/*
0154. Find Minimum in Rotated Sorted Array II

假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
请找出其中最小的元素。

思路：二分法，关键难点是理解，当右端点==中点的值时，为何可以right--来缩小范围。

参考：https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/solution/mian-shi-ti-11-xuan-zhuan-shu-zu-de-zui-xiao-shu-3/
*/

class Solution {
public:
    int findMin(vector<int>& numbers) {
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

