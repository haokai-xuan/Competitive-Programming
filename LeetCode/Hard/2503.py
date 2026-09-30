class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:
        m = len(grid)
        n = len(grid[0])
        visited = [[False] * n for _ in range(m)]

        min_heap = [(grid[0][0], 0, 0)]
        visited[0][0] = True

        heapset = set()
        heapset.add((0, 0))

        queries_with_indices = [(q, i) for i, q in enumerate(queries)]
        queries_with_indices.sort()
                    
        ans = [0] * len(queries)
        points = 0
        for (q, i) in queries_with_indices:
            while min_heap:
                node, r, c = min_heap[0]
                if node >= q:
                    break
                heappop(min_heap)
                points += 1
                visited[r][c] = True
                
                for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    if r + dr >= 0 and r + dr < m and c + dc >= 0 and c + dc < n and not visited[r + dr][c + dc]:
                        if (r + dr, c + dc) not in heapset:
                            heappush(min_heap, (grid[r + dr][c + dc], r + dr, c + dc))
                            heapset.add((r + dr, c + dc))

            ans[i] = points
        return ans