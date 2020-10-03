/*
0018. 4Sum

给定一个包含 n 个整数的数组 nums 和一个目标值 target，
判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？
找出所有满足条件且不重复的四元组。 

思路：https://leetcode-cn.com/problems/4sum/solution/shuang-zhi-zhen-jie-fa-can-zhao-san-shu-zhi-he-ge-/

使用四个指针(a<b<c<d)。固定最小的a和b在左边，c=b+1,d=_size-1 移动两个指针包夹求解。
 保存使得nums[a]+nums[b]+nums[c]+nums[d]==target的解。偏大时d左移，偏小时c右移。c和d相
 遇时，表示以当前的a和b为最小值的解已经全部求得。b++,进入下一轮循环b循环，当b循环结束后。
 a++，进入下一轮a循环。 即(a在最外层循环，里面嵌套b循环，再嵌套双指针c,d包夹求解)。

*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        // 首先将候选数排序
        sort(nums.begin(), nums.end());
        // 如果候选数小于4个，没有解答，直接返回
        if (nums.size() < 4)
            return res;
        int a, b, c, d;
        int _size = nums.size();
        for (a = 0; a <= _size - 4; a++) {
            // 避免重复，跳过重复的nums[a]
            if (a > 0 && nums[a] == nums[a - 1])
                continue;
            for (b = a + 1; b <= _size - 3; b++) {
                // 避免重复，跳过重复的nums[b]
                if (b > a + 1 && nums[b] == nums[b - 1])
                    continue;
                c = b + 1;
                d = _size - 1;
                // 活动指针c和d，当四个数的和较小时，向右移动c，当四个数的和较大时，向左移动d
                // 直到c和d相遇，则已经考察完所有当前固定的a和b的情形。
                while (c < d) {
                    if (nums[a] + nums[b] + nums[c] + nums[d] < target)
                        c++;
                    else if (nums[a] + nums[b] + nums[c] + nums[d] > target)
                        d--;
                    else {
                        res.push_back({nums[a], nums[b], nums[c], nums[d]});
                        // 避免重复，跳过重复的nums[c]
                        while (c < d && nums[c + 1] == nums[c])
                            c++;
                        // 避免重复，跳过重复的nums[d]
                        while (c < d && nums[d - 1] == nums[d])
                            d--;
                        // 如果上面循环不执行，也还是要移动指针，检查后面的组合
                        c++;
                        d--;
                    }
                }
            }
        }
        return res;
    }
};