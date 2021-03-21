/*
剑指 Offer 57 - II. 和为s的连续正数序列

输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

思路：
双指针i, j，分别指向和为target的序列的起点前一个位置，和终点。
target = 从0到j的和（记作addSum） - 从0到i的和（记作deductSum）.
开始时，设i在0，j在1。
1）addSum - deductSum正好等于target，则记录当前序列，并移动j指针继续找其他可能的序列；
2）addSum - deductSum > target，则移动i；
3）addSum - deductSum < target，则移动j。
*/

class Solution {
private:
    vector<vector<int>> res;

    void addSequence(int start, int end) {
        vector<int> newSeq;

        for (int i = start + 1; i <= end; ++i) {
            newSeq.push_back(i);
        }

        res.push_back(newSeq);
    }

public:
    vector<vector<int>> findContinuousSequence(int target) {
        long long deductSum = 0, addSum = 1;
        int i = 0, j = 1;

        while (i < j && j < target) {
            if (addSum - deductSum == target) {
                addSequence(i, j);
                ++j;
                addSum = addSum + j;
            }
            else if (addSum - deductSum > target) {
                ++i;
                deductSum = deductSum + i;
            }
            else if (addSum - deductSum < target) {
                ++j;
                addSum = addSum + j;
            }
        }

        return res;
    }
};
