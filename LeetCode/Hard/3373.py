class Solution:
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]]) -> List[int]:
        n = len(edges1) + 1
        m = len(edges2) + 1
        adj1 = defaultdict(list)
        adj2 = defaultdict(list)
        for u, v in edges1:
            adj1[u].append(v)
            adj1[v].append(u)
        for u, v in edges2:
            adj2[u].append(v)
            adj2[v].append(u)
        def dist(adj, nodes):
            ret = [-1] * nodes
            q = []
            q.append(0)
            visited = set()
            depth = 0
            while q:
                level_size = len(q)
                for j in range(level_size):
                    node = q.pop(0)
                    ret[node] = 0 if depth % 2 == 0 else 1
                    visited.add(node)
                    for neighbour in adj[node]:
                        if neighbour not in visited:
                            q.append(neighbour)
                depth += 1
            return ret



        t1 = dist(adj1, n)
        t2 = dist(adj2, m)
        t2_max = max(sum(1 for p in t2 if p == 0), sum(1 for p in t2 if p % 2 == 1))
        ans = []
        t1_even =  sum(1 for p in t1 if p == 0)
        t1_odd = sum(1 for p in t1 if p == 1)
        for i in range(n):
            res = t2_max + (t1_even if t1[i] == 0 else t1_odd)
            ans.append(res)

        return ans