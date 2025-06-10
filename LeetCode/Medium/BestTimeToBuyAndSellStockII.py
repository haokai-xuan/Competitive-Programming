class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        curr_max = 0
        for i in range(len(prices) - 1):
            if prices[i + 1] > prices[i]:
                curr_max += prices[i + 1] - prices[i]
        
        return curr_max