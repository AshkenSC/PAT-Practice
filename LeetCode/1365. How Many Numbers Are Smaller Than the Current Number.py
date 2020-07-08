# 1365. How Many Numbers Are Smaller Than the Current Number

# 思路：遍历数组num，对每个元素，检查其他所有元素是否小于它。
# （显然，有更好的解法，一个idea是先排好序，再根据序列判断一个数比多少数字大。
# 但要处理一些问题，比如排序后的数和排序前的如何对应；有相同数字如何处理等。）

from typing import List


class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        result = list()
        for num in nums:
            result.append(self.find_how_many_smaller(num, nums))
        return result

    def find_how_many_smaller(self, num, nums):
        smaller_count = 0
        for number in nums:
            if number < num:
                smaller_count += 1
        return smaller_count

