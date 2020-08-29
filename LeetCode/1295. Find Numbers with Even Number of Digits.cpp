/*
1295. Find Numbers with Even Number of Digits

给一组整数，返回其中位数是偶数的数有多少个。
*/

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (to_string(nums[i]).size() % 2 == 0)
                result++;
        }
        return result;
    }
};