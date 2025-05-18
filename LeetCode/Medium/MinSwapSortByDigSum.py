class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        def digitsSum(n):
            s = 0
            while n:
                digit = n % 10
                s += digit
                n //= 10
            return s
            
        arr = [(digitsSum(nums[i]), nums[i]) for i in range(len(nums))]
        srtd = sorted(arr)

        print(arr)

        indexed = defaultdict(int)
        for i in range(len(arr)):
            indexed[arr[i]] = i

        swaps = 0
        for i in range(len(arr)):
            if arr[i] != srtd[i]:
                temp = arr[i]
                pos = indexed[srtd[i]]
                arr[i] = arr[pos]
                arr[pos] = temp
                indexed[arr[i]] = i
                indexed[arr[pos]] = pos
                swaps += 1

        return swaps

        return swaps
        ©leetcode