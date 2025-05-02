class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        if rowIndex == 0:
            return [1]
        elif rowIndex == 1:
            return [1, 1]

        prev_arr = self.getRow(rowIndex - 1)
        
        num_to_change = rowIndex - 1
        arr = []
        arr.append(1)
        for i in range(num_to_change):
            arr.append(prev_arr[i] + prev_arr[i + 1])
        arr.append(1)

        return arr