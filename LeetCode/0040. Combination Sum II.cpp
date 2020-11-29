/*
0040. Combination Sum II

给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用一次。

思路：回溯法，注意和组合总和I不同，这里要求每个数字只能使用一次。
此外，要注意如何*去重*。第一次写，没有去重，结果如下：
输入：[10,1,2,7,6,1,5]， 8
输出：[[1,2,5],[1,7],[1,6,1],[2,6],[2,1,5],[7,1]]

在思考如何去重时，先尝试将候选列表排序，其他不变，看看规律。
发现输出为：[[1,1,6],[1,2,5],[1,7],[1,2,5],[1,7],[2,6]]
那么，尝试这样去重：在递归函数里的for循环中，当前数字candidate[i]和上一个数字相同，则跳过。
这样，由于有2个1带来的重复情形就可以消去了。
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> curCombination;

    void findCombination(vector<int>& candidate, int target, int curSum, int startIndex) {
        if (curSum == target) {
            res.push_back(curCombination);
            return;
        }
        if (curSum > target) {
            return;
        }

        for (int i = startIndex; i < candidate.size(); i++) {
            // 去重
            if (i > startIndex && candidate[i] == candidate[i - 1])
                continue;

            curCombination.push_back(candidate[i]);
            curSum += candidate[i];
            findCombination(candidate, target, curSum, i + 1);
            // 回溯
            curCombination.pop_back();
            curSum -= candidate[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        findCombination(candidates, target, 0, 0);
        return res;
    }
};
