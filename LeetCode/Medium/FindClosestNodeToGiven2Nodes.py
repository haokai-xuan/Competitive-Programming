class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        def dfs(start, depth, dists, visited):
            if start == -1 or start in visited:
                return dists
            dists[start] = depth
            visited.add(start)
            return dfs(edges[start], depth + 1, dists, visited)
        n = len(edges)
        n1_dists = dfs(node1, 0, [-1] * n, set())
        n2_dists = dfs(node2, 0, [-1] * n, set())

        # print(n1_dists)
        # print(n2_dists)
        
        ans = -1
        curr_min = float('inf')
        for i in range(n):
            if n1_dists[i] != -1 and n2_dists[i] != -1:
                temp = max(n1_dists[i], n2_dists[i])
                if temp < curr_min:
                    curr_min = temp
                    ans = i

        return ans