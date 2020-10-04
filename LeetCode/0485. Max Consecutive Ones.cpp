/*
0485. Max Consecutive Ones

给定一个二进制数组，找到最长的连续1子序列。

思路：
直接用一个变量记录最大长度

个人思路：（麻烦）
记录所有出现过的连续1子序列的长度，找到最大值

*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen = 0, currentLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                currentLen++;
            }
            else {
                if (currentLen > maxLen)
                    maxLen = currentLen;
                currentLen = 0;
            }
        }

        // 这样写是为了处理最后一位为1的情形
        return max(currentLen, maxLen);
    }
};

/*
class Solution1 {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> oneSeqLen;  // 用来记录数组中的所有连续1子序列的长度
        int begin = 0, end = 0;
        for (int i = 0; i < nums.size(); i++) {
            // 未在记录子序列，遇到1
            if (begin == end && nums[i] == 1) {
                begin = i;
                end = i + 1;
            }
            // 正在记录一个子序列，遇到1
            else if (begin != end && nums[i] == 1) {
                end++;
            }
            // 未在记录子序列，遇到0
            else if (begin == end && nums[i] == 0) {
                continue;
            }
            // 正在记录子序列，遇到0
            else if (begin != end && nums[i] == 0) {
                oneSeqLen.push_back(end - begin);
                begin = end;
            }
            // 正在记录子序列，遇到结尾
            else if (begin != end && i == nums.size() - 1) {
                oneSeqLen.push_back(end - begin);
            }
           
        }
        return *max_element(oneSeqLen.begin(), oneSeqLen.end());
    }
};
*/