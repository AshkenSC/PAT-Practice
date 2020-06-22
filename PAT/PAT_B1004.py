# PAT B1004

# data存放原始数据；
# dataDict存放(分数：个人信息)键值对（分数均不同，可做key）；
# scores存放分数，用max，min直接找其中最值，以便在dataDict中定位最值
# string.split(str, num)，按照参数str分割string，分割出num+1个子串

data = []
dataDict = {}
scores = []
number = int(input())
for i in range(number):
    data.append(input().split())
    data[i][2] = int(data[i][2])
    dataDict[data[i][2]] = data[i][0] + ' ' + data[i][1]
    scores.append(data[i][2])
print(dataDict[max(scores)])
print(dataDict[min(scores)])

'''
# 解法2
num = int(input())
data = {}
for i in range(num):
    info = input()
    splitInfo = info.split(' ')
    data[int(splitInfo[2])] = splitInfo[:-1]
print(data[max(data.keys())][0], data[max(data.keys())][1])
print(data[min(data.keys())][0], data[min(data.keys())][1])
'''