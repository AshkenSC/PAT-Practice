/*
0162. Find Peak Element

思路1：依次遍历。时间复杂度不符合要求。

思路2：二分法。
当前比右边小，那么肯定在右边会有峰顶，最差情况走到头，也是一个峰顶； 
如果当前比左边小，那么肯定在左边会有峰顶，最差情况一路走到头，也是一个峰顶。

*/

#include <vector>
using namespace std;

// 思路1：遍历，时间复杂度O(n)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        
        vector<long> numsCopy;
        for (int i = 0; i < nums.size(); i++) {
            numsCopy.push_back(nums[i]);
        }

        numsCopy.insert(numsCopy.begin(), 1, -INT64_MAX);
        numsCopy.push_back(-INT64_MAX);
        for (int i = 1; i < numsCopy.size() - 1; i++) {
            if (numsCopy[i] > numsCopy[i - 1] && numsCopy[i] > numsCopy[i + 1])
                return i - 1;
        }
        return 0;
    }
    
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            // 如果mid比右边的数大，那么左边一定有峰值
            // 最坏情况是mid左端点，也一定有峰值
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            }
            // 如果mid比左边的数大，那么右边一定有峰值
            // 最坏情况mid + 1是右端点，也一定有峰值
            else {
                left = mid + 1;
            }    
        }
        return left;
    }
};