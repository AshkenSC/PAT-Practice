/*
0003. Longest Substring Without Repeating Characters

给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

思路：
一开始错了，然后参考了这个解答里的图解
https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/longest-substring-without-repeating-characters-b-2/

核心是：
没有重复字母时，调整右边界
有重复字母时，调整左边界


设置两个索引start, end，指向子串的开始和结束位置。
设置一个集合appeared，存放字符串中出现过的字符。

当end < s.length时，进行以下循环：
    每次将当前end指向的位置字符和appeared进行比较。
        如果s[end]不在appeared里：
            将s[end]添加到appeared
            end向后移动一位
        如果s[end]在appeared里：
            maxLen = max(maxLen, end - start)
            （窗口内出现重复字母，调整左边界）
            左边界向左移动一直移动到和end所指的位置元素重复的位置后面
这时end == s.length了，最后再比较一次maxLen = max(maxLen, end - start)

返回maxLength。
*/

#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       if (s.size() == 0) {
           return 0;
       }

       int start = 0, end = 0;
       int maxLen = 0;
       unordered_set<char> appeared;

       while (end < s.size()) {
           // 当窗口内没有重复字母时，调整右边界
            if (appeared.count(s[end]) == 0) {
               appeared.emplace(s[end++]);
            }
            // 当窗口内出现重复字母时，调整左边界
            // 因为重复的不一定就是s[start]，左边界向右移动一直移动到和end所指的位置元素重复的位置
            // 移动过程中的元素也都要从appeared里删除。
            else {
                maxLen = max(maxLen, end - start);
                while (appeared.count(s[end]) != 0) {
                    appeared.erase(s[start++]);
                }
            }
       }

       maxLen = max(maxLen, end - start);
       return maxLen;
    }
};