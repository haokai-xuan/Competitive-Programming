class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = defaultdict(list)
        for s in strs:
            new_s = ''.join(sorted(s))
            mp[new_s].append(s)

        ans = []
        for s in mp:
            ans.append(mp[s])
        
        return ans