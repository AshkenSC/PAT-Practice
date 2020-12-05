'''
0133. Clone Graph

给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。

典例题！

参考：https://leetcode-cn.com/problems/clone-graph/solution/dfs-he-bfs-by-powcai/

思路：
错误思路：BFS遍历，对于访问过的结点，将其值修改为'visited'，表示访问过了。
这样不行，只是遍历到了每个结点，但不能完整建立起连接关系。

正确思路1：DFS
遍历每个结点，只要访问过，就放到字典visited里。字典键值对为，原node->clone node
在遍历到一个结点时，首先判断它是否visited，如果已经访问过，就直接返回visited字典里对应的克隆结点；
如果没有被访问过，就遍历其邻居，递归调用访问函数。

正确思路2：BFS（很不熟练）
和DFS一样，用一个字典存储访问过的结点。
不同的是使用队列选择即将访问的结点。（回忆一下层序遍历的思想）
开局首先将题目给定结点入队。然后出队，访问，存入visited，
查看所有邻居，是否visited过，将没访问过的存入队列。
'''

from typing import Deque


class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


# bfs
class Solution:
    def __init__(self) -> None:
        super().__init__()
        self.visited = dict()

    def bfs(self, node: 'Node'):
        if node is None:
            return
        clone = Node(node.val)
        self.visited[node] = clone
        queue = list()
        queue.insert(0, node)
        while queue:
            cur_node = queue.pop(0)
            for neighbor in cur_node.neighbors:
                if neighbor not in self.visited:
                    self.visited[neighbor] = Node(neighbor.val)
                    queue.append(neighbor)
                self.visited[cur_node].neighbors.append(self.visited[neighbor])
        return clone
            
    def cloneGraph(self, node: 'Node') -> 'Node':
        return self.bfs(node)

# dfs
class Solution:
    def __init__(self) -> None:
        super().__init__()
        self.visited = dict()

    # 返回当前结点及其孩子的拷贝
    def dfs(self, node: 'Node'):
        if node is None:
            return
        if node in self.visited:
            return self.visited[node]
        new_node = Node(node.val)
        self.visited[node] = new_node
        for neighbor in node.neighbors:
            new_node.neighbors.append(self.dfs(neighbor))
        return new_node

    def cloneGraph(self, node: 'Node') -> 'Node':
        if node == None:
            return None
        res = self.dfs(node)
        return res


ns = [Node(i, []) for i in range(0, 5)]
ns[1].neighbors = [ns[2], ns[4]]
ns[2].neighbors = [ns[1], ns[3]]
ns[3].neighbors = [ns[2], ns[4]]
ns[4].neighbors = [ns[3], ns[1]]

sol = Solution()
res = sol.cloneGraph(ns[1])
print(res.val)