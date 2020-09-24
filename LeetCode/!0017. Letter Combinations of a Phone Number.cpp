/*
0017. Letter Combinations of a Phone Number

给定一串数字2-9，输出其对应的所有可能的字符串序列。
一个数字对应3-4个英文字母，就像电话号码盘上那样。

思路：回溯法。
*/

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() == 0)
            return result;
        unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string combination;
        backtrack(result, phoneMap, digits, 0, combination);
        return result;
    }

    void backtrack(vector<string>& result, unordered_map<char, string>& phoneMap, 
    const string& digits, int index, string& combination) {
        if (index == digits.length())
            result.push_back(combination);
        else {
            char digit = digits[index];
            const string& letters = phoneMap[digit];
            for (const char& letter: letters) {
                combination.push_back(letter);
                backtrack(result, phoneMap, digits, index + 1, combination);
                combination.pop_back();
            }
        }
    }
};