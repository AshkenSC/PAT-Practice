# PAT B1011

case_num = int(input())
for i in range(0, case_num):
    entry = input()
    numbers = entry.split(' ')
    a = int(numbers[0])
    b = int(numbers[1])
    c = int(numbers[2])
    print('Case #' + str(i + 1) + ': ', end='')
    if a + b > c:
        print('false')
    else:
        print('true')
