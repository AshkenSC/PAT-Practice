/*
0080. Remove Duplicates from Sorted Array II

给定一个增序排列数组 nums ，你需要在 原地 删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

思路1：
参考官方解答。

思路2（失败）：
用指针start和end分别指向重复元素的起点和终点位置。
start和end都从起点开始，然后移动end到重复元素的末尾。
如果end - start + 1 > 2，则说明重复元素出现超过两次，需要删减。此时从start这边开始删减，直到只剩2个元素。
然后start和end同时指向下一个元素，重复上述循环。
*/

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, count = 1;
        while (i < nums.size()) {
            // 如果当前数字和前一个元素相同
            if (nums[i] == nums[i - 1]) {
                count++;
                // 如果相同数字计数已经大于2个，需要删除
                if (count > 2) {
                    nums.erase(nums.begin() + i);
                    // 删除元素后，要更新遍历指针的位置
                    i--;
                }
            }
            // 如果当前数字和前一个数字不同，重置相同元素计数变量
            else {
                count = 1;
            }
            // 每轮移动指针
            i++;
        }
        return nums.size();
    }
};
