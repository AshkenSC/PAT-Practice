/*
0448. Find All Numbers Disappeared in an Array

给定一个整数数组，1 ≤ a[i] ≤ n（n是数组大小）。有些元素出现两次，有些只出现一次。
找到所有一次都没出现过的数。你能否在O(n)时间内，不用额外空间实现它？

思路：
遍历数组a的元素，根据元素的取值，将其作为索引找到的数组的值+n。比如遍历到a[i]=3，则将a[3]的值加n。
这样要注意的是，再往后会遇到加n以后的数组值，所以每次取数组值的时候，需要a[i] % a.size()。这样，最后哪个位置的值小于等于n，哪个位置就是没出现的数。
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> disappearedNumbers;
        for (int i = 0; i < nums.size(); i++) {
            int index = (nums[i] - 1) % nums.size();
            nums[index] += nums.size();
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= nums.size())
                disappearedNumbers.push_back(i + 1);
        }
        return disappearedNumbers;
    }
};