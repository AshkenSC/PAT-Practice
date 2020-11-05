/*
0187. Repeated DNA Sequences

编写一个函数来找出所有目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。

思路：
设置一个map：appeared，用于存储出现过的子串和它们出现的次数。
设置一个vector：res，用于存储重复出现的子串。

设置一个长度为10的滑动窗口。
每次向后滑动一个字符，并检查appeared。
    如果其中已经有了该子串，则
        再检查出现次数是否大于1，大于1则不再更新res，等于1则向res添加当前子串。
        更新该子串出现次数+1。
    如果其中没有该子串，则
        新增键值对，并设出现次数为1。
返回res作为结果。
*/

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> appeared;
        vector<string> res;

        if (s.size() <= 10)
            return res;

        // 窗口向后滑动，找重复子串
        for (int i = 0; i <= s.size() - 10; i++) {
            string currentSub = s.substr(i, 10);
            // 如果已经出现过该子串
            if (appeared.count(currentSub) > 0) {
                // 已经出现，且本次是第二次出现
                if (appeared[currentSub] == 1)
                    res.push_back(currentSub);
                // 更新计数
                appeared[currentSub]++;
            }
            // 如果该子串还没出现过
            else {
                appeared[currentSub] = 1;
            }
        }

        return res;
    }
};