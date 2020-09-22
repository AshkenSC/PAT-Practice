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
    
    bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 首先统计元素出现次数，建立字典
        map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        // pair代表map中的每一个元素
        // 使用优先队列实现小顶堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for (auto& [num, count] : freq) {
            // 如果堆中元素已经满k个了，插入时就需要删除元素了
            if (q.size() == k) {
                // 如果当前堆顶计数值（堆中最小值）小于当前元素计数值，则移除堆顶元素，并插入当前元素入堆
                if (q.top().second < count) {
                    q.pop();
                    q.emplace(num, count);
                }
            }
            else {
                    q.emplace(num, count);
            }
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.top().first);
            q.pop();
        }
        return result;
    }
};