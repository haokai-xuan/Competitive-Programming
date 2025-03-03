class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        left = []
        middle = []
        right = []

        for i in nums:
            if i == pivot:
                middle.append(i)
            elif i < pivot:
                left.append(i)
            else:
                right.append(i)

        return left + middle + right