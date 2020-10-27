/*
0205. Isomorphic Strings

给定两个字符串 s 和 t，判断它们是否是同构的。
如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

思路：遍历两个字符串，用字典记录出现的字母及出现过的所有位置。
例如egg，记录为{e:[0], g:[1, 2]}
输出两个字典的values构成的集合，只要相等即可。

但集合中不能存set，vector这种unhashable类型，懵逼了。
*/

#include <unordered_set>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, vector<int>> s_occur;
        map<char, vector<int>> t_occur;
        
        // 遍历s和t，得到出现位置集合
        for (int i = 0; i < s.size(); i++) {
            if (s_occur.count(s[i]) > 0) {
                s_occur[s[i]].emplace_back(i);
            }
            else {
                vector<int> occur_pos;
                occur_pos.emplace_back(i);
                s_occur[s[i]] = occur_pos;
            }
        }
        for (int i = 0; i < t.size(); i++) {
            if (t_occur.count(t[i]) > 0) {
                t_occur[t[i]].emplace_back(i);
            }
            else {
                vector<int> occur_pos;
                occur_pos.emplace_back(i);
                t_occur[t[i]] = occur_pos;
            }
        }

        // 输出两个结点的values构成的集合
        // 注意！不能这样写，因为vector是unhashable type
        // 还是改用python写吧 我好菜啊
        unordered_set<vector<int>> s_set, t_set;
        for (auto &it : s_occur) {
            s_set.emplace(it.second);
        }
        for (auto &it : t_occur) {
            t_set.emplace(it.second);
        }

        // 对比两个集合是否相等
        if (t_set == s_set)
            return true;
        else
            return false;
    }
};