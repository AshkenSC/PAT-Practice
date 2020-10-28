/*
0219. Contains Duplicate II

给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，
并且 i 和 j 的差的 绝对值 至多为 k。

思路:遍历数组，将所有数和他们出现的索引存入字典，字典的一组键值对为：
num: lastOccurPos
如果当前数已经出现在了字典里，就计算判断curOccurPos - lastOccur <= k，
如果是，则直接返回true；如果否，则更新字典，将这次出现的位置记录为lastOccurPos。
如果遍历完还没有返回true，则返回false。
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // 记录数组中数上一次出现的位置（num:lastOccurPos)
        unordered_map<int, int> occur;
        for (int i = 0; i < nums.size(); i++) {
            // 如果当前数已经出现在了字典里，就计算判断是否有curOccurPos - lastOccur <= k，
            // 如果否，则更新字典，将这次出现的位置记录为lastOccurPos。
            if (occur.count(nums[i]) > 0) {
                if (i - occur[nums[i]] <= k)
                    return true; 
                else
                    occur[nums[i]] = i;
            }
            else {
                occur[nums[i]] = i;
            }     
        }
        return false;
    }
};