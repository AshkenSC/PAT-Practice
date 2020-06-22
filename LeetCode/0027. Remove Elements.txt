// LeetCode 27. Remove Element

/*
采用双指针，i和j初始都指向0；
j每次循环都移动，而仅当j指向与val相等时，才交换i和j。交换之后i才移动；
最后返回i。
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] != val) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        return i;
    }
};
