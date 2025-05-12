class Solution(object):
    def findEvenNumbers(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        evens = [num for num in digits if num % 2 == 0]
        evens.sort()
        mp = defaultdict(int)
        for i in range(len(digits)):
            mp[digits[i]] += 1
        ans = []
        for num in range(100, 1000, 2):
            candidate_mp = defaultdict(int)
            temp = num
            if temp % 10 not in evens:
                continue
            for i in range(3):
                candidate_mp[temp % 10] += 1
                temp /= 10
            valid = True
            for key, cnt in candidate_mp.items():
                if cnt > mp[key]:
                    valid = False
                    break
            if valid:
                ans.append(num)
        return ans