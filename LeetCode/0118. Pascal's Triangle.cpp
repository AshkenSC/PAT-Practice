/*

0118. Pascal's Triangle

给定正整数n，生成杨辉三角的前n行。

*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        if (numRows == 0)
            return result;

        result.push_back(vector<int>(1, 1));
        for (int i = 2; i <= numRows; i++) {
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
        return result;
    }
};
