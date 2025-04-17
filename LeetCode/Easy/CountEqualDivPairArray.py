class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        index_map = defaultdict(list)
        N = len(nums)
        for i in range(N):
            index_map[nums[i]].append(i)

        ans = 0

        for num, indexes in index_map.items():
            if len(indexes) > 1:
                for i in range(len(indexes)):
                    for j in range(i + 1, len(indexes)):
                        if (indexes[i] * indexes[j]) % k == 0:
                            ans += 1

        return ans