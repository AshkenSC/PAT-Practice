/*
0079. Word Search

给定一个二维网格和一个单词，找出该单词是否存在于网格中。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

思路：回溯法。
对每个字母，如果排列顺序正确，就继续向相邻元素扩展，一旦发现不正确，就return。直到最后找到完整匹配，才返回true。
由于一个单元格不能被重复使用，因此将使用过的单元格内容改为'0'，
这样在遍历到之前的单元格时就会因内容不匹配而回退。

第二遍写，思路很快就想到了，但在一些测试用例（比如[['a']]和细节上卡住了。
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool doExist = false;

    void backtrack(vector<vector<char>>& board, string word, string curStr, int row, int col) {
        // 刚找到了匹配，或者之前已经找到匹配
        if (curStr == word || doExist == true) {
            doExist = true;
            return;
        }
        // 新增加的字母不匹配，返回上一层
        // 卡住了，注意：之前没加curLen > 0，导致函数在第一层时下标访问错误
        int curLen = curStr.size();
        if (curLen > 0 && curStr[curLen - 1] != word[curLen - 1]) {
            return;
        }
        // 新增加的字母若匹配，则继续向四周寻找
        else {
            curStr += board[row][col];
            char thisChar = board[row][col];
            board[row][col] = '0';
            // 向上寻找
            if (row != 0) {
                backtrack(board, word, curStr, row - 1, col);                
            }
            // 向下寻找
            if (row != board.size() - 1) {
                backtrack(board, word, curStr, row + 1, col);
            }
            // 向左寻找
            if (col != 0) {
                backtrack(board, word, curStr, row, col - 1);
            }
            // 向右寻找
            if (col != board[0].size() - 1) {
                backtrack(board, word, curStr, row, col + 1);
            }
            // 回溯
            curStr.pop_back();
            board[row][col] = thisChar;
        }
    
    }

    bool exist(vector<vector<char>>& board, string word) {
        // 之前的写法没办法处理board为1*1的情况，只好无耻地打补丁
        if (board.size() == 1 && board[0].size() == 1 && word.size() == 1) {
            if (board[0][0] == word[0])
                return true;
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (doExist == true)
                    break;
                backtrack(board, word, "", i, j);
            }
        }

        return doExist;
    }
};
