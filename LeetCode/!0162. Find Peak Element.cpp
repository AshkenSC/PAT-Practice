/*
0162. Find Peak Element

思路1：依次遍历。时间复杂度不符合要求。

思路2：二分法。
当前比右边小，那么肯定在右边会有峰顶，最差情况走到头，也是一个峰顶； 
如果当前比左边小，那么肯定在左边会有峰顶，最差情况一路走到头，也是一个峰顶。

二刷，补充解释：
为什么二分查找大的那一半一定会有峰值呢？（即nums[mid]<nums[mid+1]时，mid+1~N一定存在峰值） 
我的理解是，首先已知 nums[mid+1]>nums[mid]，那么mid+2只有两种可能，一个是大于mid+1，一个是小于mid+1，
小于mid+1的情况，那么mid+1就是峰值，
大于mid+1的情况，继续向右推，如果一直到数组的末尾都是大于的，那么可以肯定最后一个元素是峰值，
因为nums[nums.length]=负无穷
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
        // 注意！这里right从nums.size()-1开始，下面while的结束条件却不是left <= right
        // 需要注意这一点比较特殊。
        
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