class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        mp = defaultdict(int)

        for num in nums:
            mp[num] = (mp[num] + 1) % 2

        for value in mp.values():
            if value != 0:
                return False

        return True