'''
0605. Can Place Flowers

假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。

思路：左右边界不好处理，于是考虑在左右加一个0，这样左右边界就能当作普通位置同等对待了。

'''

class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        temp = [0] + flowerbed + [0]
        for i in range(1, len(temp) - 1):
            if temp[i - 1] == 0 and temp[i] == 0 and temp[i + 1] == 0:
                temp[i] = 1
                n -= 1
        return n <= 0