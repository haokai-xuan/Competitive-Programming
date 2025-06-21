class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        mp = defaultdict(int)
        for c in word:
            mp[c] += 1

        arr = list(mp.values())
        arr.sort()

        print(arr)

        ans = float('inf')
        
        for i in range(len(arr)):
            base = arr[i]
            to_del = 0
            for j in range(len(arr)):
                if arr[j] < base:
                    to_del += arr[j]
                elif arr[j] > base + k:
                    to_del += arr[j] - (base + k)

            ans = min(ans, to_del)
        return ans