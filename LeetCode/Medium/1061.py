class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        adj = defaultdict(list)
        n = len(s1)
        for i in range(n):
            c1 = s1[i]
            c2 = s2[i]
            if c1 != c2:
                adj[c1].append(c2)
                adj[c2].append(c1)

        def dfs(start, visited):
            if start in visited:
                return start
            visited.add(start)
            ans = start
            for c in adj[start]:
                ans = min(ans, dfs(c, visited))

            return ans

        chars = []
        for c in baseStr:
            visited = set()
            temp = dfs(c, visited)
            chars.append(temp)

        ans = ''.join(chars)

        return ans