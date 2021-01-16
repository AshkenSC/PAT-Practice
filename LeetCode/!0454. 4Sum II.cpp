/*
0454. 4Sum II

思路：将数组分为两部分，问题转化为在AB中取两个数求和，在CD中找是否有两个数的和是其相反数。
将数组分为两部分，问题转化为在AB中取两个数求和，在CD中找是否有两个数的和是其相反数。
用一个map存储：在AB中各取一个数求和，这样的和一共有多少组合？
然后在CD中，每次各取一个数，求和取反，在这字典里找其对应的value，将这个value加入res。
如果在CD中找到的数，其相反数在字典里并不存在，就会直接返回0.

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
