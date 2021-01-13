/*
0692. Top K Frequent Words

给一非空的单词列表，返回前 k 个出现次数最多的单词。
返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。

思路1：偷懒法。
首先用unordered_map统计，然后转存到vector排序，最后输出前k个项。

思路2：小根堆。
*/

class Solution {
public:
    static bool cmp(pair<string, int>& a, pair<string, int>& b) {
        // 当出现次数不同时从大到小
        // 当出现次数相同，字符串按字典序
        if (a.second != b.second) {
            return a.second > b.second;
        }
        else {
            return a.first < b.first;
        }
    }

   
    vector<string> topKFrequent(vector<string>& words, int k) {
        // 用unordered_map统计出现次数
        unordered_map<string, int> stat;
        for (auto word : words) {
            if (stat.count(word) == 0) {
                stat[word] = 1;
            }
            else {
                ++stat[word];
            }
        }
        // 将统计结果转存到vector里便于排序
        vector<pair<string, int>> stat_list;
        for (auto word_count : stat) {
            stat_list.push_back(word_count);
        }
        // 对统计结果用sort排序，取前k个项
        sort(stat_list.begin(), stat_list.end(), cmp);
        vector<string> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(stat_list[i].first);
        }

        return res;
    }
};