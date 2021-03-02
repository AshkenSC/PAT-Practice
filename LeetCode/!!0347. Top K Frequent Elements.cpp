/*
0347. Top K Frequent Elements

给定一个非空整数数组，返回k个最常出现的元素。
要求算法的时间复杂度必须优于O(n log n)，其中n为数组大小。

2021-01-12更新：
做完215后，尝试使用大顶堆，但是在本机输出正确，却在力扣输出错误。

2021-01-12更新：
topk （前k大）用小根堆，维护堆大小不超过 k 即可。
每次压入堆前和堆顶元素比较，如果比堆顶元素还小，直接扔掉，否则压入堆。
检查堆大小是否超过 k，如果超过，弹出堆顶。复杂度是 nlogk。

避免使用大根堆，因为你得把所有元素压入堆，复杂度是 nlogn，而且还浪费内存。如果是海量元素，那就挂了。

求前 k 大，用小根堆，求前 k 小，用大根堆。

自己实现堆：https://leetcode-cn.com/problems/top-k-frequent-elements/solution/python-dui-pai-xu-by-xxinjiee/

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


// 使用priority_queue
class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 统计出现次数
        map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // 用优先队列实现小顶堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for (auto entry : freq) {
            if (q.size() < k) {
                q.emplace(entry);
            }
            else {
                if (q.top().second < entry.second) {
                    q.pop();
                    q.emplace(entry);
                }
            }
        }

        // 输出结果
        vector<int> res;
        while (q.empty() == false) {
            res.push_back(q.top().first);
            q.pop();
        }
        return res;
    }
};

// 2021-01-12重做，个人失败版本
class Solution {
public:
    void maxHeapify(vector<pair<int, int>>& a, int i, int heapSize) {
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int largest = i;
        
        if (left < heapSize && a[left].second > a[largest].second) {
            largest = left;
        }
        if (right < heapSize && a[right].second > a[largest].second) {
            largest = right;
        }
        if (largest != i) {
            swap(a[largest], a[i]);
            maxHeapify(a, largest, heapSize);
        }
    }

    void buildMaxHeap(vector<pair<int, int>>& a, int heapSize) {
        for (int i = heapSize / 2; i > 0; --i) {
            maxHeapify(a, i, heapSize);
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 用map统计数字出现的次数
        unordered_map<int, int> occur;
        for (auto num : nums) {
            if (occur.count(num) == 0) {
                occur[num] = 1;
            }
            else {
                ++occur[num];
            }
        }
        // 用vector<pair<int, int>> 存储统计结果，便于排序
        vector<pair<int, int>> occurList;
        for (auto stat : occur) {
            occurList.push_back(pair<int, int>(stat.first, stat.second));
        }

        // 根据occur构建大根堆
        int heapSize = occurList.size();
        buildMaxHeap(occurList, heapSize);

        // 保存结果
        vector<int> res;
        for (int i = occurList.size() - 1; i >= occurList.size() - k; i--) {
            res.push_back(occurList[0].first);
            swap(occurList[0], occurList[i]);
            --heapSize;
            maxHeapify(occurList, 0, heapSize);
        }

        return res;
    }
};
