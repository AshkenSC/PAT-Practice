/*
0073. Set Matrix Zeroes

给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

思路：原地算法有点难想。
方法就是利用数组的首行和首列来记录 0 值。
从数组下标的 A[1][1] 开始遍历。
那么首行首列两个布尔值记录首行首列是否需要置0。

补充说明：那么首行首列是不是被”破坏数据“了？
其实没有的，因为要修改的首行首列元素，他所在的那个行/列本来就要设0的！也就如一个评论所说：
“矩阵中某个数为零，则将该数所在行的第一个数置零，所在列的第一个数置零，
即matrix[0][j] = matrix[i][0] = 0;，
这样并不会影响该列该行首个数的取值，因为他们最后都会被置零。
即让首行首列记录哪一列有零，哪一行有零”
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 判断首行是否设0，记录在rowFlag
        bool rowFlag = false;
        for (int i = 0; i < matrix[0].size(); i++) {
            if (matrix[0][i] == 0) {
                rowFlag = true;
                break;
            }
        }

        // 判断首列是否设0，记录在colFlag
        bool colFlag = false;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                colFlag = true;
                break;
            }
        }

        // 遍历，将要设0的行列记录在第0行，第0列
        // 如果(i, j)为0，则i行，j列都设为0
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // 设i列为0
        for (int i = 1; i < matrix[0].size(); i++) {
            if (matrix[0][i] == 0) {
                for (int j = 0; j < matrix.size(); j++) {
                    matrix[j][i] = 0;
                }
            }
        }

        // 设i行为0
        for (int i = 1; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < matrix[0].size(); j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // 处理0行0列
        if (rowFlag){
            for (int i = 0; i < matrix[0].size(); i++) {
                matrix[0][i] = 0;
            }
        }
        if (colFlag){
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};


