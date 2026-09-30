class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        def getXORTotal(lst: List[int]) -> int:
            ret = 0

            for i in lst:
                ret ^= i

            return ret

        def getAllSubsets(lst: List[int]) -> List[List[int]]:
            if len(lst) == 0:
                return [[]]
            
            subsets = []
            first = lst[0]
            rest = lst[1:]

            rest_subsets = getAllSubsets(rest)
            subsets.extend(rest_subsets)

            rest_subsets_cpy = copy.deepcopy(rest_subsets)
            for subset in rest_subsets_cpy:
                subset.append(first)
                subsets.append(subset)

            return subsets

        ans = 0
        list_of_subsets = getAllSubsets(nums)
        for subset in list_of_subsets:
            ans += getXORTotal(subset)

        return ans