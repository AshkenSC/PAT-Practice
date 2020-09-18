/*
0215. Kth Largest Element in an Array

找到一个未排列数组里第k大的数。

思路1：
用冒泡排序法，第k轮就一定能排到第k大的数。

思路2：
大根堆排序法。首先将整个树完整构造为一个大根堆，然后依次弹出根节点k次（弹出也就是交换到树末尾并不再访问），
注意每一次弹出（交换根节点，缩小堆范围）都要重新建立堆。
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution1 {
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

class Solution {
public:

    // 从结点i开始递归建堆
    void buildMaxHeap(vector<int>& a,  int i, int heapSize) {   
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int largest = i;
        if (left < heapSize && a[left] > a[largest])
            largest = left;
        if (right < heapSize && a[right] > a[largest])
            largest = right;
        if (largest != i) {
            swap(a[i], a[largest]);
            buildMaxHeap(a, largest, heapSize);
        }           
        
    }

    // 完整构造大根堆
    void maxHeap(vector<int>& a, int heapSize) {
        for (int i = heapSize / 2; i >= 0; i--) {
            buildMaxHeap(a, i, heapSize);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size();
        // 构造大根堆
        maxHeap(nums, heapSize);
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; i--) {
            // 将最大的元素和末尾元素相交换
            swap(nums[0], nums[i]);
            // 交换到末尾的元素不再属于堆，heapSize减小
            heapSize--;
            // 交换完以后失去大根堆特性，需要重新堆整体建堆
            buildMaxHeap(nums, 0, heapSize);
        }
        return nums[0];
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 3,2,1,5,6,4 };
    cout << sol.findKthLargest(nums, 2);
}