/*
0215. Kth Largest Element in an Array

找到一个未排列数组里第k大的数。

思路1：
用冒泡排序法，第k轮就一定能排到第k大的数。

思路2：
大根堆排序法。首先将整个树完整构造为一个大根堆，然后依次弹出根节点k次（弹出也就是交换到树末尾并不再访问），
注意每一次弹出（交换根节点，缩小堆范围）都要重新调整堆。

思路3：
小根堆排序法。维护一个大小为k的小根堆。
首先在原数组从0到k-1构建一个小根堆。然后从k到数组尾巴，与堆顶比较。一旦比堆顶大，就交换，调整堆。
最后堆顶就是第k大的数。
*/

#include <vector>
#include <iostream>
using namespace std;


// 小根堆
class Solution {
private:
    void heapify(vector<int>& nums, int i, int heapSize) {
        int left = i * 2 + 1, right = i * 2 + 2;
        int currentMin = i;

        if (left < heapSize && nums[left] < nums[currentMin]) {
            currentMin = left;
        }
        if (right < heapSize && nums[right] < nums[currentMin]) {
            currentMin = right;
        }

        if (currentMin != i) {
            swap(nums[currentMin], nums[i]);
            heapify(nums, currentMin, heapSize);
        }
    }

    void buildHeap(vector<int>& nums, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i) {
            heapify(nums, i, heapSize);
        }
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        // 建立一个k大小的小根堆
        buildHeap(nums, k);
        // 遍历nums中第k + 1以后的数，如果比堆顶大，则交换，并调整堆
        for (int i = k; i < nums.size(); ++i) {
            if (nums[i] > nums[0]) {
                swap(nums[i], nums[0]);
                // 注意这里的heapSize，不能写nums.size()
                heapify(nums, 0, k);
            }
        }

        // 输出第k大的数
        return nums[0];
    }
};

// 大根堆
class Solution {
public:
    void maxHeapify(vector<int>& a, int i, int heapSize) {
       int left = 2 * i + 1, right = 2 * i + 2, largest = i;

       if (left < heapSize && a[left] > a[largest]) {
           largest = left;
       }
       if (right < heapSize && a[right] > a[largest]) {
           largest = right;
       }

       if (largest != i) {
           swap(a[largest], a[i]);
           maxHeapify(a, largest, heapSize);
       }
    }

    void buildMaxHeap(vector<int>& nums, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i) {
            maxHeapify(nums, i, heapSize);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);

        for (int i = nums.size() - 1; i > nums.size() - k; --i) {
            swap(nums[0], nums[i]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }

        return nums[0];
    }
};

// 冒泡排序
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int temp;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < nums.size() - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }   
            }
        }

        return nums[nums.size() - k];
    }
};


int main() {
    Solution sol;
    vector<int> nums = { 3,2,1,5,6,4 };
    cout << sol.findKthLargest(nums, 2);
}