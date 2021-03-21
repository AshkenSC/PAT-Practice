# 输入n, m, C
integers = input()
integers = integers.split()
integers = [int(num) for num in integers]
n = integers[0]
m = integers[1]
c = integers[2]

# 输入奶茶数组
data = input()
data = data.split()
data = [int(num) for num in data]

# 对奶茶分组，使得子分组和的最大值最小
# 求出这个最大值，记作max_sum
def check(x):
    total, cnt = 0, 1
    for num in data:
        if total + num > x:
            cnt += 1
            total = num
        else:
            total += num
    return cnt <= m

left = max(data)
right = sum(data)
while left < right:
    mid = (left + right) // 2
    if check(mid):
        right = mid
    else:
        left = mid + 1

max_sum = left
# 最终结果 = 奶茶总量最大的组 / 喝奶茶速度 （向上取整）
# 如果可以整除，就直接输出
# 如果不能整除，就还需要+1
if (max_sum % c == 0):
    print(max_sum // c)
else:
    print(max_sum // c + 1)

# ------草稿纸分割线


# 对奶茶分组，使得子分组和的最大值最小
'''
def split(data, m):
        def check(x):
            total, cnt = 0, 1
            for num in data:
                if total + num > x:
                    cnt += 1
                    total = num
                else:
                    total += num
            return cnt <= m
        
        left = max(data)
        right = sum(data)
        while left < right:
            mid = (left + right) // 2
            if check(mid):
                right = mid
            else:
                left = mid + 1
        
        return left
'''