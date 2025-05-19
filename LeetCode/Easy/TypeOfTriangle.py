class Solution:
    def triangleType(self, nums: List[int]) -> str:
        s = sum(nums)
        for i in range(3):
            for j in range(i + 1, 3):
                if nums[i] + nums[j] <= s - (nums[i] + nums[j]):
                    return "none"

        mp = defaultdict(int)
        for i in range(3):
            mp[nums[i]] += 1
        
        if len(mp) == 1:
            return "equilateral"
        elif len(mp) == 2:
            return "isosceles"
        else:
            return "scalene"