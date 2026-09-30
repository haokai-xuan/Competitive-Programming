class NumArray:

    def __init__(self, nums: List[int]):
        self.nums = nums
        self.ps = [nums[0]]

        for i in range(1, len(self.nums)):
            self.ps.append(self.ps[i - 1] + self.nums[i])

    def sumRange(self, left: int, right: int) -> int:
        if left == 0:
            return self.ps[right]
        else:
            return self.ps[right] - self.ps[left - 1]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)