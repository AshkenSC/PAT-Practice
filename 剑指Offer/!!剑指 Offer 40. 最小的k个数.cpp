/*
剑指 Offer 40. 最小的k个数

输入整数数组 arr ，找出其中最小的 k 个数。
例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

典型top K问题。
思路1：快速排序变形。
思路2：小根堆。
思路3：大根堆（容量为k）。

参考：
https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/solution/tu-jie-top-k-wen-ti-de-liang-chong-jie-fa-you-lie-/
*/

// 大根堆（容量为k）
class Solution {
public:
    void heapify(vector<int>& a, int i, int heapSize) {
        int left = i * 2 + 1, right = i * 2 + 2;
        int curMax = i;

        if (left < heapSize && a[curMax] < a[left]) {
            curMax = left;
        }
        if (right < heapSize && a[curMax] < a[right]) {
            curMax = right;
        }
        if (curMax != i) {
            swap(a[i], a[curMax]);
            heapify(a, curMax, heapSize);
        }
    }

    void buildHeap(vector<int>& a, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i) {
            heapify(a, i, heapSize);
        }
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (arr.size() <= k) {
            return arr;
        }

        // 对前k个数建立堆
        // 对第k + 1个数开始，就只比较堆头和arr[i]，如果堆头更大就交换之
        buildHeap(arr, k);
        for (int i = k; i < arr.size(); ++i) {
            if (arr[i] < arr[0]) {
                swap(arr[i], arr[0]);
                heapify(arr, 0, k);
            }
        }

        // 输出前k个
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(arr[i]);
        }
        return res;
    }
};

// 小根堆
class Solution {
public:
    void minHeapify(vector<int>& arr, int i, int heapSize) {
        int left = i * 2 + 1, right = i * 2 + 2;
        int curMin = i;

        if (left < heapSize && arr[curMin] > arr[left]) {
            curMin = left;
        }
        if (right < heapSize && arr[curMin] > arr[right]) {
            curMin = right;
        }
        if (curMin != i) {
            swap(arr[curMin], arr[i]);
            minHeapify(arr, curMin, heapSize);
        }
    }

    void buildMinHeap(vector<int>& arr, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i) {
            minHeapify(arr, i, heapSize);
        }
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int heapSize = arr.size();
        buildMinHeap(arr, heapSize);

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(arr[0]);
            // 将当前堆顶交换到数组末尾，并减小heapsize
            // 当前堆顶就此打入冷宫
            swap(arr[0], arr[heapSize - 1]);
            --heapSize;
            minHeapify(arr, 0, heapSize);
        }

        return res;
    }
};


// 快速排序变形
class Solution {
public:

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        if (k == 0) {
            return res;
        }
        else if (arr.size() <= k) {
            return arr;
        }

        // 原地不断划分
        partitionArray(arr, 0, arr.size() - 1, k);

        for (int i = 0; i < k; ++i) {
            res.push_back(arr[i]);
        }
        return res;
    }

    void partitionArray(vector<int>& arr, int low, int high, int k) {
        // 进行一次partition, 得到一个正确排在第m的数
        // 同时，比该数小的都在它左边，比该数大的都在他右边
        int m = partition(arr, low, high);

        // 恰好k == m，则partition后，前m个数已满足题目要求，故直接返回
        if (k == m) {
            return;
        }
        // k < m，则需要在m左侧进一步排序，寻找
        else if (k < m) {
            partitionArray(arr, low, m - 1, k);
        }
        // k > m，则需要在m右侧进一步排序，寻找
        else {
            partitionArray(arr, m + 1, high, k);
        }
    }

    // 快速排序，并返回本次正确排序的数的位置
    int partition(vector<int>& a, int low, int high) {
        int i = low;
        int j = high + 1;
        int v = a[low];
        
        while (true) {
            while (a[++i] < v) {
                if (i == high) break;
            }
            while (a[--j] > v)  {
                if (j == low) break;
            }

            if (i >= j) break;

            swap(a[i], a[j]);
        }
        swap(a[low], a[j]);

        return j;
    }
};
