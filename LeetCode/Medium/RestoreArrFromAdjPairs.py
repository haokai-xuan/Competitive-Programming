class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        n = len(adjacentPairs) + 1
        
        adj = defaultdict(lambda: [])
        for a, b in adjacentPairs:
            adj[a].append(b)
            adj[b].append(a)

        start = None
        for key in adj:
            if len(adj[key]) == 1:
                start = key

        visited = set([start])
        ans = [start]
        while len(ans) < n:
            curr = ans[-1]
            for neighbour in adj[curr]:
                if neighbour not in visited:
                    visited.add(neighbour)
                    ans.append(neighbour)

        return ans