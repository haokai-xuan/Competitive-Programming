class Solution:
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]], k: int) -> List[int]:
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

        def maxTree2Coverage():
            ans = 0
            for i in range(m):
                q = []
                q.append(i)
                depth = 0
                coverage = 0
                visited = set()
                while q and depth <= k - 1:
                    level_size = len(q)
                    coverage += level_size
                    for j in range(level_size):
                        node = q.pop(0)
                        visited.add(node)
                        for neighbour in adj2[node]:
                            if neighbour not in visited:
                                q.append(neighbour)
                    depth += 1
                ans = max(ans, coverage)

            return ans

        def maxTree1Coverage(start):
            q = []
            q.append(start)
            depth = 0
            coverage = 0
            visited = set()
            while q and depth <= k:
                level_size = len(q)
                coverage += level_size
                for j in range(level_size):
                    node = q.pop(0)
                    visited.add(node)
                    for neighbour in adj1[node]:
                        if neighbour not in visited:
                            q.append(neighbour)
                depth += 1

            return coverage
        
        ans = []
        t2_coverage = maxTree2Coverage()
        for i in range(n):
            coverage = maxTree1Coverage(i) + t2_coverage
            ans.append(coverage)

        return ans