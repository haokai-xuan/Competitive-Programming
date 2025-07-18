class Solution:
    def unhappyFriends(self, n: int, preferences: List[List[int]], pairs: List[List[int]]) -> int:
        rank = [[float('inf')] * n for i in range(n)]
        
        for i in range(len(preferences)):
            lst = preferences[i]
            for j in range(len(lst)):
                rank[i][lst[j]] = j

        cnt = 0

        partner = [0] * n
        for i in range(n // 2):
            partner[pairs[i][0]] = pairs[i][1]
            partner[pairs[i][1]] = pairs[i][0]

        print(partner)

        for x in range(n):
            y = partner[x]
            for u in preferences[x]:
                if u == y:
                    break
                v = partner[u]

                if rank[x][u] < rank[x][y] and rank[u][x] < rank[u][v]:
                    cnt += 1
                    break

        return cnt