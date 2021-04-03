/*
剑指 Offer 66. 构建乘积数组

给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

思路：
参考解答：
https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/solution/cji-hu-shuang-bai-de-shuang-xiang-bian-l-fuuk/
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> b(n, 1);

        // 计算矩阵下半部分每一行的乘积，从上往下
        for (int i = 1; i < n; ++i) {
            b[i] = b[i - 1] * a[i - 1];
        }

        // 记录矩阵上半部分每一行的乘积，从下往上
        int product = 1;
        // 逐行计算每一行对角线两侧乘积
        for (int i = n - 2; i >= 0; --i) {
            product = product * a[i + 1];
            b[i] = b[i] * product;
        }

        return b;
    }
};
