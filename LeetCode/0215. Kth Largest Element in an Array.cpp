/*
0215. Kth Largest Element in an Array

找到一个未排列数组里第k大的数。

思路1：
用冒泡排序法，第k轮就一定能排到第k大的数
*/

#include <vector>
#include <iostream>
using namespace std;

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