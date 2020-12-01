/*
0047. Permutations II

给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

思路：可包含重复数字，意味着无法再用哈希的方法记录某个数字是否已经用过。
也许也可以哈希？只不过不直接记录“值为a的数字已经用过”，
而是记录“在nums中编号为i的数字已经用过”。

心路历程：
一开始，只通过判定used[i]是否为false，结果并不能剪枝，还是会重复输出。
后来，想到通过判断if (i > startIndex && nums[i] == nums[i - 1]）则直接continue，又走进另一个极端：完全没结果。
然后看liweiwei参考答案。有了第三版成功版。
https://leetcode-cn.com/problems/permutations-ii/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liwe-2/

为什么需要if (i > startIndex && nums[i] == nums[i - 1] && used[i - 1] == false)
其中的used[i - 1] == false，意味着前一个元素不仅相同，而且还没使用，等待进行排列。
试想，对于数列[1, 1', 2]，进行排列。

首先是1做开头，[1, 1'2], [1, 21']，接下来1被重新设为used == false了，轮到1'做开头了。
但由于1和1'完全相等，因此1'开头一定是得到一系列和1开头完全相同的排列。也就是说，要把1'开头的排列完全去除。
这样，判断标准就是：nums[i] == nums[i - 1] && used[i - 1] == false

那么，当nums[i] == nums[i - 1] && used[i - 1] == true，是什么情形呢？
那就是以1开头，然后进入下一层递归，遍历到了1'，这时1已经被使用了，还在等待排列完成。
这时不能结束循环，不然就无法得到完整的排列了。所以，不能单纯的用nums[i] == nums[i - 1]做跳过循环的条件。
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> curPerm;
    vector<bool> used;

    void backtrack(vector<int>& nums, int len, int startIndex) {
        // 保存当前排列
        if (curPerm.size() == len) {
            res.push_back(curPerm);
            return;
        }
        // 递归排列
        for (int i = startIndex; i < len; i++) {
            if (i > startIndex && nums[i] == nums[i - 1] && used[i - 1] == false)
                continue;
            if (used[i] == false) {
                used[i] = true;
                curPerm.push_back(nums[i]);
                backtrack(nums, len, startIndex);
                // 回溯
                used[i] = false;
                curPerm.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int len = nums.size();
        // 初始化used数组
        for (int i = 0; i < len; i++)
            used.push_back(false);
        // 排序nums
        sort(nums.begin(), nums.end());

        backtrack(nums, len, 0);
        return res;
    }
};
