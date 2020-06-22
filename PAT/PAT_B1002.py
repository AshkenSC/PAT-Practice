# PAT B1002

hanzi = ['ling', 'yi', 'er', 'san', 'si', 'wu', 'liu', 'qi', 'ba', 'jiu']
sumInt = 0

data = input()
for i in range(len(data)):
    sumInt = sumInt + int(data[i])
sumStr = str(sumInt)

final = ''
for i in range(len(sumStr)):
    final += hanzi[int(sumStr[i])]
    if i != len(sumStr) - 1:
        final += ' '

print(final)
