'''
0313. Super Ugly Number

编写一段程序来查找第 n 个超级丑数。
超级丑数是指其所有质因数都是长度为 k 的质数列表 primes 中的正整数。

思路：模仿丑数2写法。

'''

class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        ugly_set = [1]
        pointers = [0] * len(primes)
        while len(ugly_set) < n:
            candidates = [ugly_set[pointers[i]] * primes[i] for i in range(len(primes))]
            new_ugly = min(candidates)
            ugly_set.append(new_ugly)
            for i in range(len(primes)):
                if new_ugly == ugly_set[pointers[i]] * primes[i]:
                    pointers[i] += 1
        
        return ugly_set[n - 1]
        