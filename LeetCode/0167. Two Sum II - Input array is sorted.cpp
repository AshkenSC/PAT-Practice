/*
0167. Two Sum II - Input array is sorted

给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

思路：要利用升序排列啊！！！升序排列！！我是猪吧！

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2);
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] < target)
                i++;
            else if (numbers[i] + numbers[j] > target)
                j--;
            else {
                res[0] = i + 1;
                res[1] = j + 1;
                break;
            }
        }
        return res;
    }
};