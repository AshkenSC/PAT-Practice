/*
0049. Group Anagrams

给定任意一个字符串数组strs，将字母异位词合成为一组。你可以任意顺序返回答案。

思路：构造一个字母组合映射到异位词集合的map。
构造方法是：遍历字符串数组，将每个单词的字符用sort排序，这样异位词就能对应同一个顺序的字母序列。
然后再遍历该map，取出所有的second value即可。
*/

#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> anagrams;
        // 先对所有单词中字母排序，这样所有异位词就能对应到同一个序列
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            anagrams[temp].push_back(strs[i]);
        }
        // 取出所有的异位词集合
        vector<vector<string>> result;
        for (auto iter = anagrams.begin(); iter != anagrams.end(); iter++) {
            result.push_back(iter->second);
        }
        return result;
    }
};