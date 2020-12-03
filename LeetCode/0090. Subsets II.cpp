/*
0090. Subsets II

给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。

思路：回溯法。
注意先将候选数组排序。这样才可以实现：
如果当前数字和前一个数字一样，则跳过当前数字。
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> curSubSet;

    void backtrack(vector<int>&nums, int start_index, int len) {
        // 将当前组合放入结果列表
        res.push_back(curSubSet);
        // 如果当前起始index已经到达终点，退出
        if (start_index == len)
            return;
        // 继续寻找子集
        for (int i = start_index; i < len; i++) {
            // 如果当前数字和前一个数字一样，则跳过当前数字
            if (i > start_index && nums[i] == nums[i - 1])
                continue;
            curSubSet.push_back(nums[i]);
            backtrack(nums, i + 1, len);
            curSubSet.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int len = nums.size();
        // 先排序，才能剪枝跳过重复的
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, len);
        return res;
    }
};

