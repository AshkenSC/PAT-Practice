/*
剑指 Offer 48. 最长不含重复字符的子字符串

请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

太菜了！太菜了！做了2个小时，一看别人解答却如此简洁！

思路：
哈希表统计： 遍历字符串 s 时，使用哈希表统计 各字符最后一次出现的索引位置 。
左边界 i 获取方式： 遍历到 s[j] 时，可通过访问哈希表 dic[s[j]] 获取最近的相同字符的索引i 。

参考：
https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/solution/mian-shi-ti-48-zui-chang-bu-han-zhong-fu-zi-fu-d-9/
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int current = 0;
        int result = 0;
        int currentLength = 0;
        unordered_map<char, int> occur;

        for (int i = 0; i < s.size(); ++i) {
            if (occur.count(s[i]) == 0) {
                current += 1;
            }
            else {
                // 注意这个判断很关键，不能直接current = i - occur[s[i]]
                // 否则的话，可能在s[i]与上一个重复s[i]之间存在有重复字母的串
                // 例如：abba！不判断的话，走到第二个a处就会计算成current = 3-0 = 3
                if (current < i - occur[s[i]]) {
                    current += 1;
                }
                else {
                    current = i - occur[s[i]];
                }
            }
            occur[s[i]] = i;
            result = max(current, result);
        }

        return result;
    }
};

