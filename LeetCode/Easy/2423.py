class Solution:
    def equalFrequency(self, word: str) -> bool:
        if len(word) == 2:
            return True
        
        mp = defaultdict(int)
        ltrs = set()
        for c in word:
            mp[c] += 1
            ltrs.add(c)

        if len(word) == len(mp):
            return True

        for c in ltrs:
            mp[c] -= 1
            if not mp[c]:
                del mp[c]
            ch = None
            for l in ltrs:
                if l != c:
                    ch = l
                    break
            if (all(freq == mp[l] for freq in mp.values())):
                return True
            mp[c] += 1

        return False
        