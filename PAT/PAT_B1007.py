# PAT B1007

import math


def is_prime(num):
    for i in range(2, int(math.sqrt(num) + 1)):
        if num % i == 0:
            return False
    return True


# 输入n并转为整数
n = input()
n = int(n)
# 保存个数
cnt_prime = 0

for i in range(5, n + 1):
    if is_prime(i - 2) and is_prime(i):
        cnt_prime += 1

print(cnt_prime)
