class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        N = len(tops)
        mp = defaultdict(int)
        for i in range(N):
            mp[tops[i]] += 1
            mp[bottoms[i]] += 1

        i = 0
        while mp and i < 6:
            key = max(mp, key=mp.get)
            top_cnt = 0
            bottom_cnt = 0
            valid = True
            for j in range(N):
                if tops[j] != key and bottoms[j] != key:
                    valid = False
                    break
                elif tops[j] == key and bottoms[j] == key:
                    top_cnt += 1
                    bottom_cnt += 1
                elif tops[j] == key:
                    top_cnt += 1
                else:
                    bottom_cnt += 1
            if valid:
                return N - max(top_cnt, bottom_cnt)
            else:
                del mp[key]
            
            i += 1

        return -1