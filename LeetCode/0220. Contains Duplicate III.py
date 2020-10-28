'''
0220. Contains Duplicate III

在整数数组 nums 中，是否存在两个下标 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值小于等于 t ，且满足 i 和 j 的差的绝对值也小于等于 ķ 。
如果存在则返回 true，不存在返回 false。

思路：利用桶的原理
https://leetcode-cn.com/problems/contains-duplicate-iii/solution/li-yong-tong-de-yuan-li-onpython3-by-zhou-pen-chen/

'''

class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        if t < 0 or k < 0:
            return False
        
        all_buckets = {}
        bucket_size = t + 1
        for i in range(len(nums)):
            bucket_num = nums[i] // bucket_size  # 确定放入的桶
            
            # 当前桶中已经有元素，这俩个之间相差一定不超过t （假设索引差不超过ｋ）
            if bucket_num in all_buckets:
                return True
            
            all_buckets[bucket_num] = nums[i]  # 将nums[i]放入桶

            # 可能存在前面一个桶的元素与当前桶元素差不超过t（假设索引差不超过ｋ）
            if (bucket_num - 1) in all_buckets.keys() and \
            abs(all_buckets[bucket_num - 1] - all_buckets[bucket_num]) <= t:
                return True

            # 可能存在后面一个桶的元素与当前桶元素差不超过t（假设索引差不超过ｋ）
            if (bucket_num + 1) in all_buckets.keys() and \
            abs(all_buckets[bucket_num + 1] - all_buckets[bucket_num]) <= t:
                return True
            
            # 如果上面几个都不成立，更新桶
            # 注意维护桶中元素与当前元素索引差
            # 保证**所有**桶和当前加入的桶的索引差最大不超过k！
            if i >= k:
                all_buckets.pop(nums[i - k] // bucket_size)
        
        return False