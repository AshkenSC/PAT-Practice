/*
0169. Majority Element

给定一个数组，找到里面出现次数最多的数，这个数一定出现不小于n/2次。

思路（摩尔投票法，对拼消耗）：从第一个数开始count=1，遇到相同的就加1，遇到不同的就减1，减到0就重新换个数开始计数，总能找到最多的那个。

注意numCount初始值，和计数归零后选择哪个数作为新的currentValue
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int numCount = 1;
        int currentValue = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == currentValue) {
                numCount++;
            }
            else {
                numCount--;
                if (numCount == 0) {
                    currentValue = nums[i + 1];
                }
            }
        }
        return currentValue;
    }
};