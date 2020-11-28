/*
0036. Valid Sudoku

判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

思路：
对每行和每列，构建一个set，存储出现过的数字，这样一共是9+9=18个set
对每个九宫格，构建一个set，存储出现过的数字，一共是9个set，将其放在3x3的二维vector：box[m][n]里
遍历所有格子：
对board[i][j]的格子内容：
    如果当前格子有数字，检查col[j]和row[i]的set里，是否有该元素。如果有，则返回false。如果没有，加入对应set
    接下来判断是否符合九宫格要求：
        0 <= i < 3, m = 0
        3 <= i < 6, m = 1
        6 <= i < 9, m = 2
        
        0 <= j < 3, n = 0
        3 <= j < 6, n = 1
        6 <= j < 9, n = 2
    一言以蔽之，根据i / 3 或者 j / 3确定m和n
    然后判断格子中的数是否在box[m][n]中，如果在，返回false，如果不在，加入对应set
通过上述所有检定，仍然没有返回false，则返回true

*/

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> col(9);
        vector<unordered_set<char>> row(9);
        vector < vector<unordered_set<char>> > box(3, vector<unordered_set<char>>(3));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                // 如果当前格子不是数字，跳过
                if (board[i][j] == '.')
                    continue;

                // 字符转数字
                // 检查col[j]和row[i]以及box[i / 3][j / 3]的set里，是否有该元素
                if (col[j].count(board[i][j]) > 0 || 
                    row[i].count(board[i][j]) > 0 ||
                    box[i / 3][j / 3].count(board[i][j]) > 0)
                        return false;
                else {
                    col[j].emplace(board[i][j]);
                    row[i].emplace(board[i][j]);
                    box[i / 3][j / 3].emplace(board[i][j]);
                }
            }
        }

        return true;
    }
};
