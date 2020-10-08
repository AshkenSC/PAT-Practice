/*
119. Pascal's Triangle II

给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。


*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result;

        result.push_back(vector<int>(1, 1));
        for (int i = 2; i <= rowIndex + 1; i++) {
            vector<int> row(i);
            row[0] = 1;
            for (int j = 1; j < i; j++) {
                if (j == i - 1) {
                    row[j] = 1;
                    break;
                }
                else {
                    row[j] = result[i - 2][j - 1] + result[i - 2][j];
                }
            }
            result.push_back(row);
        }
        return result[rowIndex];
    }
};