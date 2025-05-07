class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        rows = len(moveTime)
        cols = len(moveTime[0])
        heap = []
        heappush(heap, (0, 0, 0))
        cache = [[float('inf')] * cols for _ in range(rows)]
        visited = [[False] * cols for _ in range(rows)]
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        while heap:
            time, r, c = heappop(heap)
            if visited[r][c]:
                continue

            visited[r][c] = True

            for dr, dc in dirs:
                new_r = r + dr
                new_c = c + dc

                if new_r < 0 or new_c < 0 or new_r >= rows or new_c >= cols:
                    continue
                new_time = max(moveTime[new_r][new_c], time) + 1
                if new_time < cache[new_r][new_c]:
                    cache[new_r][new_c] = new_time
                    heappush(heap, (new_time, new_r, new_c))

        return cache[rows - 1][cols - 1]