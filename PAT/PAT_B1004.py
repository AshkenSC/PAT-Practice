# PAT B1004

# data���ԭʼ���ݣ�
# dataDict���(������������Ϣ)��ֵ�ԣ���������ͬ������key����
# scores��ŷ�������max��minֱ����������ֵ���Ա���dataDict�ж�λ��ֵ
# string.split(str, num)�����ղ���str�ָ�string���ָ��num+1���Ӵ�

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
# �ⷨ2
num = int(input())
data = {}
for i in range(num):
    info = input()
    splitInfo = info.split(' ')
    data[int(splitInfo[2])] = splitInfo[:-1]
print(data[max(data.keys())][0], data[max(data.keys())][1])
print(data[min(data.keys())][0], data[min(data.keys())][1])
'''