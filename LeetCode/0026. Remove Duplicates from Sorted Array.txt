// LeetCode 26. Remove Duplicates from Sorted Array

/*
使用双指针i和j。每次循环中：
1. 当i和j所指向的元素不同时，先移动一次i，再交换他们元素的位置。若相同，则不交换；
2. 执行上述判断后，向后移动一位j。
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) {
            return nums.size();
        }

        int i = 0, j = 1;
        while(j < nums.size()) {
            if(nums[i] != nums[j]) {
                swap(nums[++i], nums[j]);
            }
            j++;
        }
        return i + 1;
    }
};
