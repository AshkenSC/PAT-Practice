/*
剑指 Offer 21. 调整数组顺序使奇数位于偶数前面

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

思路：头尾双指针。
但是我一开始犯了个错误，就是一开始循环里没有写continue。
导致在一趟循环里可能front和back同时挪动，结果在判断front<back之前就交错了。
这样一交错之后，又正好满足了nums[front] % 2 == 0 && nums[back] % 2 == 1
把刚才交换的又换回去了，导致错误！
*/

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int front = 0, back = nums.size() - 1;
        while (front < back) {
            if (nums[front] % 2 == 1) {
                ++front;
                continue;
            }
            if (nums[back] % 2 == 0) {
                --back;
                continue;
            }
            if (nums[front] % 2 == 0 && nums[back] % 2 == 1) {
                swap(nums[front], nums[back]);
            }
        }

        return nums;
    }
};
