class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        visited = [False] * n

        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        def dfs(node: int, component: List[int]) -> None:
            visited[node] = True
            component.append(node)

            for u in adj[node]:
                if not visited[u]:
                    dfs(u, component)

        ans = 0
        for i in range(n):
            if not visited[i]:
                component = []
                dfs(i, component)
                valid = True
                for j in component:
                    if len(adj[j]) != len(component) - 1:
                        valid = False
                        break
                if valid:
                    ans += 1

        return ans