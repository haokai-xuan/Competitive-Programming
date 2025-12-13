from collections import defaultdict
adj = defaultdict(list)
with open('input-day11.txt') as f:
    lines = f.readlines()
for line in lines:
    idx = line.index(':')
    node = line[:idx]
    adj[node].extend(line[idx + 1:].split())

dist = defaultdict(int) # node -> number of paths from node to 'out'
for node in adj:
    dist[node] = -1

def dfs(node):
    if node == 'out':
        return 1
    if dist[node] != -1:
        return dist[node]
    
    ans = 0
    for neighbour in adj[node]:
        ans += dfs(neighbour)
    
    dist[node] = ans
    return ans

ans = dfs('you')
print(ans)