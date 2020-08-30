/*
0046. Permutations

给一组互不相同的数，返回他们所有可能的排列顺序。

思路：回溯法。
将数组分为两个部分：已经排列的部分（设[0, first-1]）和还没排列的部分（设为[first, n-1]）。
设当前要排列的数为first位，待填写的数下标为i，那么就将first和i位的数相交换，这样就当作[0, first]完成了交换，剩下没交换的位置位[first+1, n-1]。
然后在此基础上进行递归。
递归后将first和i位的数位置还原，再准备将first位与i+1位的数进行交换。
*/

class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& output, int first, int len) {

        if (first == len) {
            result.push_back(output);
            return;
        }
        else {
            for (int i = first; i < len; i++) {
                swap(output[i], output[first]);
                backtrack(result, output, first + 1, len);
                swap(output[i], output[first]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(result, nums, 0, nums.size());
        return result;
    }
};