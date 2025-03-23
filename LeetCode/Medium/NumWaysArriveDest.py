class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        adj = defaultdict(list)
        for u, v, w in roads:
            adj[u].append((w, v))
            adj[v].append((w, u))

        MOD = 10**9 + 7

        min_heap = [(0, 0)] # (cost, node)
        min_cost = [float("inf")] * n

        path_count = [0] * n
        path_count[0] = 1

        while min_heap:
            cost, node = heappop(min_heap)

            for neighbour_cost, neighbour in adj[node]:
                if cost + neighbour_cost < min_cost[neighbour]:
                    min_cost[neighbour] = cost + neighbour_cost
                    path_count[neighbour] = path_count[node]
                    heappush(min_heap, (cost + neighbour_cost, neighbour))
                elif cost + neighbour_cost == min_cost[neighbour]:
                    path_count[neighbour] = (path_count[neighbour] + path_count[node]) % MOD

        return path_count[n - 1]