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









