class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        adj = defaultdict(list)
        cell = n * n
        for i in range(n):
            if n % 2 == i % 2:
                for j in range(n):
                    if board[i][j] != -1:
                        adj[cell] = board[i][j]
                    cell -= 1
            else:
                for j in range(n - 1, -1, -1):
                    if board[i][j] != -1:
                        adj[cell] = board[i][j]
                    cell -= 1

        q = deque([1])
        dist = [-1] * ((n * n) + 1)

        dist[1] = 0

        while q:
            curr = q.popleft()
            for i in range(curr + 1, min(curr + 7, n * n + 1)):
                new_pos = i
                if new_pos in adj:
                    new_pos = adj[new_pos]
                if dist[new_pos] == -1:
                    dist[new_pos] = dist[curr] + 1
                    q.append(new_pos)
                if new_pos == n * n:
                    return dist[new_pos]


        return dist[n * n]

