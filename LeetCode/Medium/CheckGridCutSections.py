class Solution:
    def checkValidCuts(self, n: int, rectangles: List[List[int]]) -> bool:
        def check(arr: list[int]) -> bool:
            arr.sort()

            count = 0
            prev_end = -1
            for start, end in arr:
                if prev_end <= start:
                    count += 1

                prev_end = max(prev_end, end)

            return count >= 3

        arr_x = [(start, end) for start, _, end, _ in rectangles]
        if check(arr_x):
            return True

        arr_y = [(start, end) for _, start, _, end in rectangles]
        return check(arr_y)