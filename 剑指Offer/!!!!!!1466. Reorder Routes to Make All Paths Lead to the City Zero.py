'''
1466. Reorder Routes to Make All Paths Lead to the City Zero

2021.03.19 
携程笔试题！没做出来！！！抄答案都没做出来！！！是猪吧！！！

思路：
用一个集合记录可达的点。遍历所有路径。
如果终点已知可达，起点尚不可达，恰好可推出起点可达。
如果起点已知可达，终点尚不可达，说明经过一次逆转路径操作后，终点可达。
其他情况：1）起点终点都可达，跳过；2）起点终点都不可达，等后续循环再处理
'''

class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        res = 0
        connected = {0}

        while len(connected) < n:
            for (start, end) in connections:
                # 如果终点已知可达，起点尚不可达，恰好可推出起点可达
                if end in connected and start not in connected:
                    connected.add(start)
                # 如果起点已知可达，终点尚不可达，说明经过一次逆转路径操作后，终点可达
                elif start in connected and end not in connected:
                    connected.add(end)
                    res += 1
                # 其他情况：1）起点终点都可达，跳过；2）起点终点都不可达，等后续循环再处理
        
        return res
