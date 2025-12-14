from collections import defaultdict
adj = defaultdict(list)
with open('input-day11.txt') as f:
    lines = f.readlines()
for line in lines:
    idx = line.index(':')
    node = line[:idx]
    adj[node].extend(line[idx + 1:].split())

dist = {} # node -> number of paths from node to 'out'

def dfs(node, dest):
    if node == dest:
        return 1
    if (node, dest) in dist:
        return dist[(node, dest)]
    
    ans = 0
    for neighbour in adj[node]:
        ans += dfs(neighbour, dest)
    
    dist[(node, dest)] = ans
    return ans

ans = dfs('svr', 'dac') * dfs('dac', 'fft') * dfs('fft', 'out') + dfs('svr', 'fft') * dfs('fft', 'dac') * dfs('dac', 'out')
print(ans)