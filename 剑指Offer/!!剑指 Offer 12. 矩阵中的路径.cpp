/*
剑指 Offer 12. 矩阵中的路径

请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。

思路：
回溯法经典题。一段时间不做又忘记了。
*/

class Solution {
private:
    string currentWord;
    bool doExist = false;

public:
    void search(vector<vector<char>>& board, const string& word, int row, int col) {
        if (currentWord == word || doExist) {
            doExist = true;
            return;
        }

        // 如果当前字符不匹配，就返回
        int curLen = currentWord.size();
        if (currentWord.size() > 0 && currentWord[curLen - 1] != word[curLen - 1]) {
            return;
        }
        // 如果当前字符匹配，就继续深入探索
        else {
            // 使用当前字符，就修改为‘0’，避免重复使用
            char currentChar = board[row][col];
            board[row][col] = '0';
            currentWord += currentChar;

            // 开始上下左右求索
            if (row > 0) {
                search(board, word, row - 1, col);
            }
            if (row < board.size() - 1) {
                search(board, word, row + 1, col);
            }
            if (col > 0) {
                search(board, word, row, col - 1);
            }
            if (col < board[0].size() - 1) {
                search(board, word, row, col + 1);
            }

            // 回溯
            currentWord.pop_back();
            board[row][col] = currentChar;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        // 如果是单字符词
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
                search(board, word, i, j);
            }
        }

        return doExist;
    }
};

