class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        N = len(piles)
        def validK(k):
            hours = 0
            for i in range(N):
                if piles[i] <= k:
                    hours += 1
                else:
                    hours += math.ceil(piles[i] / k)

            if hours <= h:
                return 0
            else:
                return 1

        left = 1
        right = max(piles)
        while left < right:
            mid = (left + right) // 2
            if validK(mid) == 0:
                right = mid
            else:
                left = mid + 1

        return left