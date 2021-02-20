/*
剑指 Offer 12. 矩阵中的路径

请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。

回溯法经典题。一段时间不做又忘记了。

*/

class Solution {
public:
    bool doExist = false;

    void backtrack(vector<vector<char>>& board, const string& word, string curStr, int row, int col) {
        // 如果已经存在，或者刚刚判定出已存在
        if (word == curStr || doExist) {
            doExist = true;
            return;
        }

        // 如果当前新字符不匹配，返回
        int curLen = curStr.size();
        if (curLen > 0 && curStr[curLen - 1] != word[curLen - 1]) {
            return;
        }
        // 如果匹配，则继续
        else {
            // 修改当前字符并备份
            char curChar = board[row][col];
            board[row][col] = '0';
            curStr += curChar;

            // 开始上下左右探索
            if (row > 0) {
                backtrack(board, word, curStr, row - 1, col);
            }
            if (row != board.size() - 1) {
                backtrack(board, word, curStr, row + 1, col);
            }
            if (col != 0) {
                backtrack(board, word, curStr, row, col - 1);
            }
            if (col != board[0].size() - 1) {
                backtrack(board, word, curStr, row, col + 1);
            }

            // 回溯
            board[row][col] = curChar;
            curStr.pop_back();
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 1 && board[0].size() == 1 && word.size() == 1) {
            if (board[0][0] == word[0]) {
                return true;
            }
        }
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (doExist) {
                    break;
                }
                backtrack(board, word, "", i, j);
            }
        }

        return doExist;
    }
};
