/*
0661. Image Smoother

包含整数的二维矩阵 M 表示一个图片的灰度。你需要设计一个平滑器来让每一个单元的灰度成为平均灰度 (向下舍入) ，
平均灰度的计算是周围的8个单元和它本身的值求平均，如果周围的单元格不足八个，则尽可能多的利用它们。

思路：暴力法，考虑边界情况。
*/

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> res;
        int height = M.size();
        int width = M[0].size();
        // 确定当前要计算的中心点：M[i][j]
        for (int i = 0; i < height; i++) {
            vector<int> row;
            for (int j = 0; j < width; j++) {
                // 计算M[i][j]周围点的和
                int sum = M[i][j];
                int cnt = 1;
                for (int k = i - 1; k <= i + 1; k++)
                    for (int l = j - 1; l <= j + 1; l++) {
                        // 讨论不计算的点
                        if (k < 0 || k >= height || l < 0 || l >= width
                        || (k == i && l == j))
                            continue;
                        else {
                            sum += M[k][l];
                            cnt += 1;
                        }
                    }
                
                // 计算当前中心的的平均灰度，并存入当前行中
                int avg = sum / cnt;
                row.push_back(avg);
            }
            // 保存当前行
            res.push_back(row);
        }

        return res;
    }
};

