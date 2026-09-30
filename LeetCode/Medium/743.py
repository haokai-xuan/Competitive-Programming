class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adj = defaultdict(list)

        for u, v, w in times:
            adj[u].append((w, v))

        min_heap = [(0, k)]
        visited = set()

        ans = 0

        while min_heap:
            cost, node = heappop(min_heap)

            if node in visited:
                continue

            visited.add(node)
            ans = cost

            for neighbour_cost, neighbour in adj[node]:
                heappush(min_heap, (cost + neighbour_cost, neighbour))

        if len(visited) == n:
            return ans
        else:
            return -1