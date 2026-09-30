class FindSumPairs:

    def __init__(self, nums1: List[int], nums2: List[int]):
        self.nums1 = nums1
        self.nums2 = nums2
        self.mp = defaultdict(int)
        for num in self.nums2:
            self.mp[num] += 1

    def add(self, index: int, val: int) -> None:
        old = self.nums2[index]
        self.nums2[index] += val

        self.mp[old] -= 1
        self.mp[self.nums2[index]] += 1

        if self.mp[old] <= 0:
            del self.mp[old]

    def count(self, tot: int) -> int:
        ans = 0
        for num in self.nums1:
            ans += self.mp[tot - num]

        return ans


# Your FindSumPairs object will be instantiated and called as such:
# obj = FindSumPairs(nums1, nums2)
# obj.add(index,val)
# param_2 = obj.count(tot)