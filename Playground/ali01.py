# from copy import deepcopy as dc

# # 用集合去除重复路径
# ans = set()

# def dfs(graph,trace,start):
#     #trace = dc(trace)  # 深拷贝，对不同起点，走过的路径不同

#     # 如果下一个点在trace中，则返回环
#     if start in trace:
#         index = trace.index(start)
#         tmp = [str(i) for i in trace[index:]]
#         ans.add( str(' '.join(tmp)))
#         #print(trace[index:])
#         return

#     trace.append(start)

#     # 深度优先递归递归
#     for i in graph[start]:
#         dfs(graph,trace,i)
 
# graph = {1: [2], 2: [3], 3: [1,4,5], 4: [1], 5:[3]}  # 包含大小环test图

# dfs(graph,[],1)

# print(ans)

class Solution:
    def __init__(self) -> None:
        self.a = 0

sol = Solution()
sol.a = 1

print(sol.a)





# tmp = []
# for i in route[index:]:
#     tmp.append(str(i))

# 吱吱版本
# 用邻接表保存图+dfs
# 路径指的是，从起点到环入口
# graph = {1:[node1的邻居们],2:[], ……}
from copy import deepcopy
Class Solution():
  def __init__(self):
    #如果存在多个环，result要在递归中append多次, 所以定义在函数外
  	self.result = [] 
  
  def dfs(self, graph, route, current_node):
    route = deepcopy(route)
    if current_node in route: 
      # 如果当前节点已经在路径中，说明有环,
	    # 找到环起点在路径中的位置，打印这个位置之前的
      cycle_start = route.index(current_node)
      temp = [str[i] for i in route[:cycle_start+1]]
      self.result.append(''.join(temp))
      return
    route.append(current_node)
    for neighbour in graph[node]:
      self.dfs(graph, route, neighbour)

graph = {1:[2], 2:[3,4],3:[1]}
sol = Solution()
ans = sol.dfs(graph,[],1)








