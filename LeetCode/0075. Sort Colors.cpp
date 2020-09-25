/*
0075. Sort Colors

给定一个数组nums，包含n个颜色为红，白或蓝的对象。
将他们就地排序，使得相同颜色的对象是相邻的，且颜色顺序为红，白，蓝。
这里使用整数0，1，2表示颜色红，白，蓝。

思路：使用冒泡排序。
*/

#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < nums.size() - i - 1; j++) {
                if (nums[j] > nums[j + 1])
                    swap(nums[j], nums[j + 1]);
            }

    }
};