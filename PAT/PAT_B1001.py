# PAT B1001

x = int(input())
i = 0
while x != 1:
  if x % 2 == 0:
    x = x / 2
    i = i + 1
  else:
    x = (3 * x + 1)/2
    i = i + 1
print(i)