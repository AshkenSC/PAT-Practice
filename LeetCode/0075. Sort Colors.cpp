/*
0075. Sort Colors

给定一个数组nums，包含n个颜色为红，白或蓝的对象。
将他们就地排序，使得相同颜色的对象是相邻的，且颜色顺序为红，白，蓝。
这里使用整数0，1，2表示颜色红，白，蓝。

进阶：能否想出一个仅使用常数空间的一趟扫描算法？

思路1：使用冒泡排序。

思路2：使用三指针，一次遍历。
三指针为：左指针left，右指针right，操作指针cur
每次循环，先观察cur指向的值。
如果cur=0,则将cur与left指向的值互换，然后left向右，cur向右；
如果cur=1，只右移cur；
如果cur=2，则将cur与right指向的值互换，然后**只左移动right**。
**注意循环范围！！** cur < right
*/

#include <vector>
using namespace std;

class Solution0 {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < nums.size() - i - 1; j++) {
                if (nums[j] > nums[j + 1])
                    swap(nums[j], nums[j + 1]);
            }

    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, cur = 0;
        while (cur < right) {
            if (nums[cur] == 0) 
                swap(nums[cur++], nums[left++]);
            else if (nums[cur] == 1)
                cur++;
            else if (nums[cur] == 2)
                swap(nums[cur], nums[right--]);
        }
    }
};