'''
1 1 1 4 4 5
0 0 0 3 3 4

如果多重集合里的每个数运算后满足A==B, 那么转化为非多重集合也应满足

小美和小团的班上有n个人，分别编号为1到n,其中小美的编号为1，小团的编号为2。
班上有个值日表aij.第一天由小美值日，第二天由小团值日，
接下来的每一天，如果今天是i值日，昨天是j值日，那么明天就是aij值日。
值日表是规划好的，保证今天值日的同学明天一定不值日。
小美想知道第m天值日的同学编号。

第一行n m表示n个同学和小美想知道的天数
接下来n行每行n个整数，表示值日表ai,j 有且仅有对角线数字是0

3 7
0 3 2
3 0 3
2 1 0

输出1

1 2 3 1 2 3 1

明天第几天   谁值日
3           a[1][2] = 3
4           a[3][2] = 1
5           a[1][3] = 2
6           a[2][1] = 3
7           a[3][2] = 1
'''

integers = input()
integers = integers.split()
integers = [int(num) for num in integers]
n = integers[0]
m = integers[1]

data = []
for i in range(n):
    line = input()
    line = line.split()
    line = [int(num) for num in integers]
    data.append(line)

if m == 1:
    print(1)
elif m == 2:
    print(2)
else:







# ----------------


'''
# 读取n, m
integers = input()
integers = integers.split()
integers = [int(num) for num in integers]
n = integers[0]
m = integers[1]

# 读取A
a = input()
a = a.split()
a = [int(num) for num in a]
# 去重
a = list(set(a))         

# 读取B
b = input()
b = b.split()
b = [int(num) for num in b]
# 去重
b = set(b)

x = 1
while True:
    new_a = [(num + x) % m for num in a]
    new_a = set(new_a)
    if new_a == b:
        print(x)
        break
    else:
        x += 1
'''



'''
# 保存二维数组的行列数
size = input()
size = size.split()
size = [int(num) for num in size]
m = size[0]
n = size[1]

# data为输入的 m*n 的二维数组
data = []
for i in range(m):
    line = input()
    line = line.split()
    line = [int(num) for num in line]
    data.append(line)

print(data)
'''

'''
n = int(input())
data_str = input()
data_str = data_str.split()
data = [int(num) for num in data_str]

data.sort()
res = 0
i = 0
# 遍历数组，i指向待构成题组的三个题的第一题
while i < n:
    # 凯斯1：三个数都满足条件
    if i + 2 < n and data[i + 1] - data[i] <= 10 and data[i + 2] - data[i + 1] <= 10:
        i += 3
    # 凯斯2：两个数中间差超过10，但不超过20，中间需要补1个数
    elif i + 1 < n and data[i + 1] - data[i] > 10 and data[i + 1] - data[i] <= 20:
        res += 1
        i += 2
    # 凯斯3：两个数中间差超过20，中间需要补2个数
    elif i + 1 < n and data[i + 1] - data[i] > 20:
        res += 2
        i += 1
    # 凯斯4：当前数和后面1个数差满足条件，尾部只需要补1个数
    elif i + 1 < n and data[i + 1] - data[i] <= 10:
        res += 1
        i += 2
    # 凯斯5：当前数后面没有数了，尾部需要补2个数
    elif i + 1 >= n:
        res += 2
        i += 1

print(res)
'''
        