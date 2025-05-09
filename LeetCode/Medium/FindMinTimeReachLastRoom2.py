class Solution(object):
    def minTimeToReach(self, moveTime):
        """
        :type moveTime: List[List[int]]
        :rtype: int
        """
        rows = len(moveTime)
        cols = len(moveTime[0])
        cache = [[float('inf')] * cols for _ in range(rows)]
        cache[0][0] = 0
        visited = [[False] * cols for _ in range(rows)]
        heap = []
        heappush(heap, (0, 0, 0))

        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        while heap:
            time, r, c = heappop(heap)
            if visited[r][c]:
                continue
            if r == rows - 1 and c == cols - 1:
                break

            visited[r][c] = True
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if nr < 0 or nr >= rows or nc < 0 or nc >= cols:
                    continue

                min_time = max(moveTime[nr][nc], time) + (r + c) % 2 + 1
                if min_time < cache[nr][nc]:
                    cache[nr][nc] = min_time
                    heappush(heap, (min_time, nr, nc))

        return cache[rows - 1][cols - 1]