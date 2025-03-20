class Solution:
    def minimumCost(self, n: int, edges: List[List[int]], query: List[List[int]]) -> List[int]:
        adj = defaultdict(list)

        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))

        component = 1
        components = [0] * n

        def solve(start: int) -> None:
            visited = [False] * n
            q = deque()
            q.append(start)
            visited[start] = True

            first = True
            min_cost = -1

            nodes_in_component = []
            nodes_in_component.append(start)

            while len(q) != 0:
                node = q[0]
                q.popleft()

                for neighbour, cost in adj[node]:
                    min_cost = cost if first else min_cost & cost
                    first = False

                    if not visited[neighbour]:
                        visited[neighbour] = True
                        nodes_in_component.append(neighbour)
                        q.append(neighbour)

            for node in nodes_in_component:
                mp[node] = min_cost
                components[node] = component

        mp = defaultdict(int)
        
        for i in range(n):
            if not i in mp:
                solve(i)
                component += 1

        ans = []
        print(mp)
        for s, t in query:
            if components[s] == components[t]:
                ans.append(mp[s])
            else:
                ans.append(-1)

        return ans