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
#b = set(b)
b = list(set(b))

x = 1
while True:
    is_x_valid = True
    # 逐个判断a中元素经过运算后是否能对应到b中元素
    # 一旦发现不能对应，设标志变量为false
    for i in range(len(a)):
        if (a[i] + x) % m != b[i]:
            is_x_valid = False
            break
    
    if is_x_valid:
        print(x)
        break
    else:
        x += 1
        

# while True:
#     new_a = [(num + x) % m for num in a]
#     new_a = set(new_a)
#     if new_a == b:
#         print(x)
#         break
#     else:
#         x += 1
