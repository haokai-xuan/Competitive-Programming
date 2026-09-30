class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        def can_fix(time: int) -> bool:
            total_fixed = 0
            for r in ranks:
                total_fixed += int((time / r) ** 0.5)

            return total_fixed >= cars

        left = 1
        right = max(ranks) * cars ** 2
        while left != right:
            mid = (left + right) // 2
            if can_fix(mid):
                right = mid
            else:
                left = mid + 1

        return right