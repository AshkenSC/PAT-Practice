/*
0378. Kth Smallest Element in a Sorted Matrix

给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。

思路：240类似题。参考官方解答方法三。
注意本题在二分的时候，left right mid不是索引，而是具体值。
疑问1：mid = left + (right - left) / 2 怎么保证mid一定在矩阵里？
疑问2：smaller和k比大小后，取半的逻辑还不太清楚。也就是：
为什么大于等于取right = mid，小于取left = mid + 1;
*/

#include <vector>
using namespace std;

class Solution {
public:
    int countSmaller(vector<vector<int>>& matrix, int mid) {
        int row = matrix.size(), col = matrix[0].size();
        int x = row - 1, y = 0;
        int numOfSmaller = 0;
        while (x >= 0 && y < col) {
            if (matrix[x][y] <= mid) {
                numOfSmaller += x + 1;
                ++y;
            }
            else {
                --x;
            }
        }

        return numOfSmaller;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(), col = matrix[0].size();
        int left = matrix[0][0], right = matrix[row - 1][col - 1];
        int mid, numOfSmaller;

        while (left < right) {
            mid = left + (right - left) / 2;
            numOfSmaller = countSmaller(matrix, mid);
            if (numOfSmaller == k) {
                right = mid;
            }
            else if (numOfSmaller < k) {
                left = mid + 1;
            }
            else if (numOfSmaller > k) {
                right = mid;
            }
        }

        return left;
    }
};
