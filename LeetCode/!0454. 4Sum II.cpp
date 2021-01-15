/*
0454. 4Sum II

思路：将数组分为两部分，问题转化为在AB中取两个数求和，在CD中找是否有两个数的和是其相反数。

参考：https://leetcode-cn.com/problems/4sum-ii/solution/tu-jie-fen-zu-ha-xi-si-lu-jian-dan-by-treasure-35/
*/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        unordered_map<int, int> A_B;
        for (auto& a : A) {
            for (auto& b : B) {
                ++A_B[a + b];
            }
        }
        for (auto& c : C) {
            for (auto& d : D) {
                res = res + A_B[-c - d];
            }
        }

        return res;
    }
};
