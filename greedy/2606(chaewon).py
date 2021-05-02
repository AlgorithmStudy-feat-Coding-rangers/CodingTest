def dfs(graph, root):
    visited = []
    stack = [root]

    while stack:
        node = stack.pop()
        if node not in visited:
            visited.append(node)
            if node in graph:
                stack.extend(graph[node])
    return visited


graph = {}
computerCnt = int(input())
connectedCnt = int(input())

for i in range(computerCnt):
    graph[i + 1] = []

for cnt in range(connectedCnt):
    i, j = map(int, input().split())
    graph[i].append(j)
    graph[j].append(i)

trasnferdCnt = len(dfs(graph, 1)) - 1
print(trasnferdCnt)
