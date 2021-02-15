/*
0056. Merge Intervals

给出一个区间的集合，请合并所有重叠的区间。

思路：
https://leetcode-cn.com/problems/merge-intervals/solution/tan-xin-suan-fa-java-by-liweiwei1419-3/
1. 首先将所有区间按左端点位置从低到高排序。
2. 遍历区间。如果当前遍历到的区间的左端点 > 结果集合中最后一个区间的右端点，则两个没有交集：
    将当前区间插入结果集合。
3. 如果当前遍历到的区间的左端点 <= 结果集合中最后一个区间的右端点，则两个有交集：
    将更新结果集合中最后一个区间的右端点。
    取最后一个区间的右端点和当前区间右端点中较大的那个。
*/

#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.size() == 0) {
            return res;
        }

        // 将区间按左端点进行升序排序
        // 使用lambda表达式
        sort(intervals.begin(), intervals.end(),
        [](vector<int>& a, vector<int>& b){return a[0] < b[0];});

        // 遍历区间
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            // 如果当前遍历到的区间的左端点 > 结果集合中最后一个区间的右端点，则两个没有交集：
            // 将当前区间插入结果集合
            if (intervals[i][0] > res.back()[1]) {
                res.push_back(intervals[i]);
            }
            // 如果当前遍历到的区间的左端点 <= 结果集合中最后一个区间的右端点，则两个有交集：
            // 将更新结果集合中最后一个区间的右端点。
            // 取最后一个区间的右端点和当前区间右端点中较大的那个。
            else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }

        return res;
    }
};
