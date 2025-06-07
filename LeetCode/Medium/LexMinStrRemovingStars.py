class Solution:
    def clearStars(self, s: str) -> str:
        heap = []
        include = [True] * len(s)
        mp = defaultdict(list)
        for i in range(len(s)):
            if s[i] == "*":
                include[i] = False

        for i in range(len(s)):
            c = s[i]
            if c == "*":
                if not heap:
                    continue
                lex_min = heappop(heap)
                pos = mp[lex_min].pop()
                # print(f"lex: {lex_min}, pos: {pos}")
                include[pos] = False
            else:
                mp[c].append(i)
                heappush(heap, c)

        ans = []
        for i in range(len(s)):
            if include[i]:
                ans.append(s[i])

        return "".join(ans)