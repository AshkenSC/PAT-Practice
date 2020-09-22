/*
0347. Top K Frequent Elements

给定一个非空整数数组，返回k个最常出现的元素。
要求算法的时间复杂度必须优于O(n log n)，其中n为数组大小。

思路：使用小顶堆
使用生疏的容器优先队列来实现（priority_queue)
小顶堆，堆顶为堆中出现次数最少的那个元素。最多只保存k个元素。当不满k个时直接加入堆。
当满k个时，将元素与堆顶元素比较。如果比堆顶元素还小，放弃；如果比堆顶元素大，就删除当前堆顶元素，把当前元素入堆。
最后将堆中所有元素输出即得到结果。
*/

#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 首先统计每个数字出现的个数，使用字典统计
        map<int, int> freq;
        for (auto num : nums) {
            freq[num]++;
        }

        // 使用优先队列实现小顶堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for (auto entry : freq) {
            // 如果堆中元素小于k个，直接插入
            if (q.size() < k)
                q.emplace(entry);
            // 如果堆中元素等于k了，就需要对比当前元素和堆顶元素的大小
            // 如果当前元素比堆顶元素要大，则删除堆顶元素，插入当前元素
            else {
                if (q.top().second < entry.second) {
                    q.pop();
                    q.emplace(entry);
                }
            }
        }

        // 返回结果
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.top().first);
            q.pop();
        }
        return result;
    }
};