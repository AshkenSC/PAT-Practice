# 198
'''
1 3 4 5 2

1)
假设A一共有n景点，n-1条线路，且每两个不同景点之间只有一个线路
例如 给定所有线路routes，routes[w] = [i,j]表示从经典i到j的一个有向线路
保证所有人可以游玩结束时再相同景点会合，请修改景点之间的路线方向，让每个景点最终可以到景点0
返回所需修改的最少线路数。

景点数n，路径routes

5 [[0,1],[3,1],[2,0],[2,4]]

能否反过来思考，修改最少的线路，使得0可以到达所有节点
第一次遍历：
关注含有0的线路。以0为终点的，不需要修改；以0为起点的，反向修改，res++
第二次遍历：
关注0为终点的线路的起点，记录为layers[1]数组。
检查线路中是否有路径以layers[1]节点为起点，且终点非0.如果存在，则反向修改，res++
...
第n次遍历




2)
给定一个二维数组A，假设自注意力Q K V的初始权重都是0.5
请计算A的 子注意力得分

'''

from typing import List
import heapq
import json
# Definition for a binary tree node.

'''
# data_str 存储输入的数组字符串
# d 存储维度
data_str = input()
d = input()

# data 存储转换后的输入数组
data_str = data_str.split('<trip>')
data = []
for line in data_str:
    data.append([int(num) for num in line.split()])

print(data)
'''


# 读取整行数据
data = input()
n = int(data.split()[0])
edges = json.loads(data.split()[1])
result = 0

# 保存已经能正确到达0的城市
accessible_cities = {0}  
for (left, right) in edges:
    # right是已经能到0的城市，那么left -> right后就可到0
    if right in accessible_cities:  
        accessible_cities.add(left)
    # right目前不可到城市0，left可到，那就让right -> left后到0，结果+1
    elif left in accessible_cities: 
        result += 1
        accessible_cities.add(right)

print(str(result))

'''
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def find_predecessor(self, root):
        root = root.left
        while root.right:
            root = root.right
        return root.val

    def find_successor(self, root):
        root = root.right
        while root.left:
            root = root.left
        return root.val

    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if not root:
            return None
        p = root
        while p and p.val != key:
            if p.val > key:
                p = p.left
            else:
                p = p.right
        if p:
            if not (p.left or p.right):
                p = None
            elif p.left:
                p.val = self.find_predecessor(p)
                self.deleteNode(p.left, p.val)
            else:
                p.val = self.find_successor(p)
                self.deleteNode(p.right, p.val)
        return root

a = TreeNode(5)
b = TreeNode(3)
c = TreeNode(6)
d = TreeNode(2)
e = TreeNode(4)
f = TreeNode(None)
g = TreeNode(7)
a.left = b
a.right = c
b.left =d
b.right = e
c.left = f
c.right = g
sol = Solution()
ans=sol.deleteNode(a,3)
print(ans)

        

# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()

# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()

#sol = Solution()
obj = MyQueue()
obj.push(1)
obj.push(2)
a = obj.peek()
b = obj.pop()
c = obj.empty()
'''