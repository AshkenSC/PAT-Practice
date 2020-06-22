# PAT B1006

num_str = input()

if len(num_str) == 1:
    for i in range(1, int(num_str)+1):
        print(str(i), end='')
elif len(num_str) == 2:
    for i in range(int(num_str[0])):
        print('S', end='')
    for i in range(1, int(num_str[1]) + 1):
        print(str(i), end='')
elif len(num_str) == 3:
    for i in range(int(num_str[0])):
        print('B', end='')
    for i in range(int(num_str[1])):
        print('S', end='')
    for i in range(1, int(num_str[2]) + 1):
        print(str(i), end='')
