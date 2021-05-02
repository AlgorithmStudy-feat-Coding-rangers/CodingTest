def dfs(graph, visited, root):
    stack = [root]

    while stack:
        node = stack.pop()
        if node not in visited:
            visited.append(node)
            if node in graph:
                stack.extend(graph[node])
    return visited


# make graph
graph = {}
visited = list()

n, m = map(int, input().split())
for i in range(n):
    graph[i + 1] = list()

for i in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

cnt = 0
for i in range(1, n + 1):
    if i not in visited:
        dfs(graph, visited, i)
        cnt += 1